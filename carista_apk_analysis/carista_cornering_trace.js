'use strict';

const LIB_NAME = 'libCarista.so';
const VECTOR_BYTE_LIMIT = 96;
const SYMBOLS = {
  changeSettingInternal:
    '_ZN17OperationDelegate21changeSettingInternalERKNSt6__ndk110shared_ptrI7SettingEERKNS0_6vectorIhNS0_9allocatorIhEEEERKNS1_I8ProgressEE',
  getSettingRawAddress:
    '_ZN20VagOperationDelegate20getSettingRawAddressERKNSt6__ndk110shared_ptrI7SettingEE',
  writeVagCodingCtor:
    '_ZN21WriteVagCodingCommandC1EP3EcuRKNSt6__ndk16vectorIhNS2_9allocatorIhEEEERKNS2_10shared_ptrIS7_EEN10VagEcuInfo10CodingTypeESC_',
};

const settingsByNativeId = Object.create(null);
const activeByThread = Object.create(null);

function nowIso() {
  return new Date().toISOString();
}

function sendEvent(type, payload) {
  const message = Object.assign({ ts: nowIso(), type: type }, payload || {});
  send(message);
}

function pointerText(value) {
  return value.isNull() ? '0x0' : value.toString();
}

function readHex(address, size) {
  let hex = '';
  for (let index = 0; index < size; index += 1) {
    const byteValue = Memory.readU8(address.add(index));
    hex += ('0' + byteValue.toString(16)).slice(-2);
  }
  return hex.toUpperCase();
}

function readStdVectorInfo(vectorRef, limit) {
  if (vectorRef.isNull()) {
    return null;
  }

  const begin = Memory.readPointer(vectorRef);
  const end = Memory.readPointer(vectorRef.add(Process.pointerSize));
  const size = end.sub(begin).toInt32();
  const info = {
    vector_ref: pointerText(vectorRef),
    begin: pointerText(begin),
    end: pointerText(end),
    size: size,
  };

  if (size < 0 || size > limit) {
    info.error = 'size_out_of_range';
    info.limit = limit;
    return info;
  }

  info.hex = readHex(begin, size);
  return info;
}

function readSharedVectorInfo(sharedPtrRef, limit) {
  if (sharedPtrRef.isNull()) {
    return null;
  }

  const pointee = Memory.readPointer(sharedPtrRef);
  return {
    shared_ptr_ref: pointerText(sharedPtrRef),
    pointee: pointerText(pointee),
    vector: pointee.isNull() ? null : readStdVectorInfo(pointee, limit),
  };
}

function stackForThread(threadId) {
  if (!(threadId in activeByThread)) {
    activeByThread[threadId] = [];
  }
  return activeByThread[threadId];
}

function topForThread(threadId) {
  const stack = activeByThread[threadId];
  return stack && stack.length ? stack[stack.length - 1] : null;
}

function u64Hex(low32, high32) {
  const lowHex = ('00000000' + low32.toString(16)).slice(-8);
  const highHex = ('00000000' + high32.toString(16)).slice(-8);
  return '0x' + highHex + lowHex;
}

function installJavaHooks() {
  Java.perform(function () {
    const Long = Java.use('java.lang.Long');
    const SettingRef = Java.use('com.prizmos.carista.library.model.SettingRef');
    const ChangeSettingOperation = Java.use('com.prizmos.carista.library.operation.ChangeSettingOperation');

    function javaByteArrayToHex(byteArray) {
      if (byteArray === null) {
        return null;
      }
      const array = Java.array('byte', byteArray);
      let hex = '';
      for (let index = 0; index < array.length; index += 1) {
        const byteValue = array[index] & 0xff;
        hex += ('0' + byteValue.toString(16)).slice(-2);
      }
      return hex.toUpperCase();
    }

    function safeStringCall(thunk) {
      try {
        const value = thunk();
        if (value === null || value === undefined) {
          return null;
        }
        return String(value);
      } catch (error) {
        return 'ERROR: ' + error;
      }
    }

    function describeSetting(setting, requestedValue, readValuesOperation) {
      const info = {
        class_name: safeStringCall(function () {
          return setting.getClass().getName();
        }),
        requested_value_hex: javaByteArrayToHex(requestedValue),
        thread_id: Process.getCurrentThreadId(),
      };

      info.name_res_id = safeStringCall(function () {
        return setting.getNameResId();
      });
      info.event_string = safeStringCall(function () {
        return setting.toEventString();
      });
      info.instruction = safeStringCall(function () {
        return setting.getInstruction();
      });

      try {
        const interpretation = setting.getInterpretation();
        if (interpretation !== null) {
          info.interpretation = safeStringCall(function () {
            return interpretation.toString();
          });
          info.interpretation_class = safeStringCall(function () {
            return interpretation.getClass().getName();
          });
        }
      } catch (error) {
        info.interpretation_error = String(error);
      }

      try {
        const ref = Java.cast(setting, SettingRef);
        const nativeId = ref.getNativeId();
        info.native_id = nativeId.toString();
        info.native_id_hex = '0x' + Long.toHexString(nativeId);
        settingsByNativeId[info.native_id_hex] = info;
      } catch (error) {
        info.native_id_error = String(error);
      }

      if (readValuesOperation !== null) {
        try {
          if (readValuesOperation.hasSettingValue(setting)) {
            info.current_value_hex = javaByteArrayToHex(readValuesOperation.getSettingValue(setting));
          }
        } catch (error) {
          info.current_value_error = String(error);
        }
        try {
          info.connected_ecu_tag = safeStringCall(function () {
            return readValuesOperation.getConnectedEcuTag(setting);
          });
        } catch (error) {
          info.connected_ecu_tag_error = String(error);
        }
      }

      return info;
    }

    const ctor = ChangeSettingOperation.$init.overload(
      'com.prizmos.carista.library.model.Setting',
      '[B',
      'com.prizmos.carista.library.operation.ReadValuesOperation'
    );
    ctor.implementation = function (setting, requestedValue, readValuesOperation) {
      const info = describeSetting(setting, requestedValue, readValuesOperation);
      sendEvent('change_setting_java', { setting: info });
      return ctor.call(this, setting, requestedValue, readValuesOperation);
    };

    sendEvent('status', {
      where: 'java',
      message: 'ChangeSettingOperation constructor hook installed',
    });
  });
}

function installNativeHooks() {
  const exported = {};
  Object.keys(SYMBOLS).forEach(function (key) {
    exported[key] = Module.findExportByName(LIB_NAME, SYMBOLS[key]);
  });

  if (!exported.changeSettingInternal || !exported.getSettingRawAddress || !exported.writeVagCodingCtor) {
    sendEvent('status', {
      where: 'native',
      message: 'waiting_for_libcarista_exports',
      exports: Object.fromEntries(
        Object.keys(exported).map(function (key) {
          return [key, exported[key] ? exported[key].toString() : null];
        })
      ),
    });
    setTimeout(installNativeHooks, 500);
    return;
  }

  Interceptor.attach(exported.changeSettingInternal, {
    onEnter(args) {
      try {
        this.threadId = Process.getCurrentThreadId();
        this.settingPtr = Memory.readPointer(args[1]);
        this.valueInfo = readStdVectorInfo(args[2], VECTOR_BYTE_LIMIT);
        this.metadata = settingsByNativeId[pointerText(this.settingPtr)] || null;
        const stack = stackForThread(this.threadId);
        stack.push({
          setting_ptr: pointerText(this.settingPtr),
          value: this.valueInfo,
          metadata: this.metadata,
        });
        sendEvent('change_setting_native', {
          thread_id: this.threadId,
          setting_ptr: pointerText(this.settingPtr),
          value: this.valueInfo,
          setting: this.metadata,
        });
      } catch (error) {
        sendEvent('hook_error', {
          where: 'changeSettingInternal.onEnter',
          error: String(error),
        });
      }
    },
    onLeave(retval) {
      const stack = activeByThread[this.threadId];
      if (stack && stack.length) {
        stack.pop();
      }
    },
  });

  Interceptor.attach(exported.getSettingRawAddress, {
    onEnter(args) {
      try {
        this.threadId = Process.getCurrentThreadId();
        this.settingPtr = Memory.readPointer(args[1]);
      } catch (error) {
        this.enterError = String(error);
      }
    },
    onLeave(retval) {
      if (this.enterError) {
        sendEvent('hook_error', {
          where: 'getSettingRawAddress.onEnter',
          error: this.enterError,
        });
        return;
      }

      try {
        const active = topForThread(this.threadId);
        const low32 = retval.toUInt32();
        const high32 = this.context.r1.toUInt32();
        sendEvent('get_setting_raw_address', {
          thread_id: this.threadId,
          setting_ptr: pointerText(this.settingPtr),
          setting: active ? active.metadata : settingsByNativeId[pointerText(this.settingPtr)] || null,
          raw_key_low32: '0x' + ('00000000' + low32.toString(16)).slice(-8),
          raw_key_high32: '0x' + ('00000000' + high32.toString(16)).slice(-8),
          raw_key_u64: u64Hex(low32, high32),
        });
      } catch (error) {
        sendEvent('hook_error', {
          where: 'getSettingRawAddress.onLeave',
          error: String(error),
        });
      }
    },
  });

  Interceptor.attach(exported.writeVagCodingCtor, {
    onEnter(args) {
      try {
        const threadId = Process.getCurrentThreadId();
        const active = topForThread(threadId);
        sendEvent('write_vag_coding_ctor', {
          thread_id: threadId,
          ecu_ptr: pointerText(args[1]),
          setting_ptr: active ? active.setting_ptr : null,
          setting: active ? active.metadata : null,
          ctor_value: readStdVectorInfo(args[2], VECTOR_BYTE_LIMIT),
          raw_address: readSharedVectorInfo(args[3], 16),
          coding_type: args[4].toInt32(),
          trailing_vector: readSharedVectorInfo(args[5], 16),
        });
      } catch (error) {
        sendEvent('hook_error', {
          where: 'writeVagCodingCtor.onEnter',
          error: String(error),
        });
      }
    },
  });

  sendEvent('status', {
    where: 'native',
    message: 'libCarista hooks installed',
    exports: {
      changeSettingInternal: exported.changeSettingInternal.toString(),
      getSettingRawAddress: exported.getSettingRawAddress.toString(),
      writeVagCodingCtor: exported.writeVagCodingCtor.toString(),
    },
  });
}

installJavaHooks();
installNativeHooks();
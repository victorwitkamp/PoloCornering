# Carista Reproduction Namespace Notes

This package mirrors recovered Carista native concepts as closely as the current
evidence allows.

## Native Namespace Evidence

The recovered C++ symbols do not show a top-level namespace such as `Carista::`
or `Vag::`. The Itanium names point to global C++ classes with class-owned
methods:

```text
_ZN11BaseCommand12extractState...                    -> BaseCommand::extractState
_ZN23GetVagCanEcuInfoCommand10getRequest...          -> GetVagCanEcuInfoCommand::getRequest
_ZN21WriteVagCodingCommand10getRequest...            -> WriteVagCodingCommand::getRequest
_ZN28WriteDataByIdentifierCommand10getRequest...     -> WriteDataByIdentifierCommand::getRequest
_ZN20VagOperationDelegate16writeVagUdsValue...       -> VagOperationDelegate::writeVagUdsValue
_ZN18VagCanCommunicator13readResponses...            -> VagCanCommunicator::readResponses
_ZN9ByteUtils11insertValue...                        -> ByteUtils::insertValue
```

Nested names appear where the symbols explicitly encode them:

```text
_ZN5State3Set10fatalErrorEv
  -> State::Set::fatalError()

_ZN18VagCanCommunicator12VagCanPacketC1EtNS_6OpCodeEh...
  -> VagCanCommunicator::VagCanPacket::VagCanPacket(..., VagCanCommunicator::OpCode, ...)
```

## Python Layout Rule

- `Commands/` groups command classes for readability; this is a Python package
  organization, not a proven native `Commands` namespace.
- `Models/` contains one value object per file. Some are recovered-ish native
  concepts (`VagEcuInfoWithCoding`), while others are local reproduction report
  objects (`CaristaUdsCodingWritePlan`, `TupleCandidate`).
- Root modules are used for recovered root classes/concepts such as
  `VagCanCommunicator`, `VagOperationDelegate`, `VagCanSettings`, `VagSetting`,
  `ByteUtils`, and `Types`.

## Android / DEX Namespace Evidence

The base APK has two DEX files. A lightweight Androguard descriptor scan places
the Java/native bridge classes in `classes2.dex` under the real Java package
path:

```text
com.prizmos.carista.library.model.Setting
com.prizmos.carista.library.model.SettingRef
com.prizmos.carista.library.model.SettingCategory
com.prizmos.carista.library.operation.ReadValuesOperation
com.prizmos.carista.library.operation.ChangeSettingOperation
com.prizmos.carista.library.operation.CheckSettingsOperation
com.prizmos.carista.library.operation.GetEcuInfoOperation
```

The `Android/com/prizmos/carista/library/...` subtree mirrors that DEX package
path. Those modules intentionally model the Java bridge shape only; the actual
availability map, setting catalog, and write execution still cross into native
code.
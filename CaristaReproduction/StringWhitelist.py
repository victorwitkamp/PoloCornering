from __future__ import annotations

from dataclasses import dataclass


def StringWhitelist_itemMatches(whitelist_item: str, item: str) -> bool:
    if whitelist_item.startswith("*"):
        return item.endswith(whitelist_item[1:])
    if whitelist_item.endswith("*"):
        return item.startswith(whitelist_item[:-1])
    if "." in whitelist_item:
        return len(whitelist_item) == len(item) and all(
            whitelist_char == "." or whitelist_char == item_char
            for whitelist_char, item_char in zip(whitelist_item, item)
        )
    return whitelist_item == item


@dataclass(frozen=True)
class StringWhitelist:
    items: tuple[str, ...]
    evidence: tuple[str, ...] = ()

    def itemMatches(self, whitelist_item: str, item: str) -> bool:
        return StringWhitelist_itemMatches(whitelist_item, item)

    def match(self, item: str) -> bool:
        return any(self.itemMatches(whitelist_item, item) for whitelist_item in self.items)

    def combinedItems(self, *others: "StringWhitelist") -> "StringWhitelist":
        return StringWhitelist(
            tuple(dict.fromkeys(self.items + tuple(item for other in others for item in other.items))),
            self.evidence + tuple(evidence for other in others for evidence in other.evidence),
        )
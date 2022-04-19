#!/usr/bin/python3
"""
    Lockboxes module
"""


def canUnlockAll(boxes):
    """Checks if the keys from the boxes opened can open all the boxes.
        Args:
            boxes (:obj:`list` of :obj:`list` of `int`): The list of boxes.
        Returns:
            bool: The final answer. True if all the boxes were opened, False
                otherwise.
    """
    if len(boxes) == 0:
        return False
    if len(boxes) == 1:
        return True
    keys = set([new_key for new_key in boxes[0]
                if 1 <= new_key <= len(boxes) - 1])
    for current_box in range(1, len(boxes)):
        for key in list(keys):
            keys = keys.union([new_key for new_key in boxes[key]
                               if 1 <= new_key <= len(boxes) - 1])
            if len(keys) + 1 == len(boxes):
                return True
    return False

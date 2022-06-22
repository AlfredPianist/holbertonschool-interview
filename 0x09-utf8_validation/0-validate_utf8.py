#!/usr/bin/python3
"""
    Valid UTF8 module
"""


def validUTF8(data):
    """Checks if the data input is a valid UTF-8 encoding.
        Args:
            data (:obj:`list` of `int`): The list of integers representing
                the data.
        Returns:
            bool: True if data is a valid UTF-8 encoding, False otherwise.
    """
    char_num_bytes = 0
    mask_msb_1 = 1 << 7
    mask_msb_2 = 1 << 6
    for num in data:
        mask = 1 << 7
        if char_num_bytes == 0:
            while mask & num:
                char_num_bytes += 1
                mask >>= 1
            if char_num_bytes == 0:
                continue
            if char_num_bytes == 1 or char_num_bytes > 4:
                return False
        elif not (num & mask_msb_1 and not (num & mask_msb_2)):
            return False
        char_num_bytes -= 1
    return char_num_bytes == 0

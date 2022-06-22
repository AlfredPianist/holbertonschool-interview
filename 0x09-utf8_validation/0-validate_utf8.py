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
    for byte in data:
        if not 0 <= byte <= 255:
            return False
    return True

#!/usr/bin/python3
"""
    Log parsing module
"""
import sys


def print_information(status_codes, size):
    """ Prints log information.
       Args:
           status_codes (:obj:`str` of `int`): The status codes with its hit
            count.
           size (int): The file size.
    """
    print("File size: {:d}".format(size))
    for code, count in sorted(status_codes.items()):
        if count != 0:
            print("{}: {:d}".format(code, count))


if __name__ == "__main__":
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0, "401": 0, "403": 0, "404": 0, "405": 0,
        "500": 0
    }
    size = 0
    counter = 0

    try:
        for line in sys.stdin:
            line = line.split()[::-1]

            try:
                size += int(line[0])
            except:
                pass

            try:
                status = line[1]
                if status in status_codes:
                    status_codes[status] += 1
            except:
                pass

            counter += 1
            if counter == 10:
                print_information(status_codes, size)
                counter = 0
        print_information(status_codes, size)

    except KeyboardInterrupt:
        print_information(status_codes, size)
        raise

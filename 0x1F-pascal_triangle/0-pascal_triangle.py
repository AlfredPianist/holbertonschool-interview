#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""0-pascal_triangle

This module returns a list of lists of integers representing Pascal's
triangle at n.
"""


def pascal_triangle(n):
    """Returns a list of lists with Pascal's triangle at n.
    Args:
        n (int): The number of rows of Pascal's triangle.
    Returns:
        list of list: Pascal's triangle.
    """
    triangle = []
    if n <= 0:
        return triangle
    triangle.append([1])
    if n == 1:
        return triangle
    triangle.append([1, 1])
    if n == 2:
        return triangle
    for i in range(3, n + 1):
        row = []
        tmp = [1]
        limit = i // 2 - 1 if i % 2 == 0 else i // 2
        for j in range(limit):
            tmp.append(triangle[-1][j] + triangle[-1][j + 1])
        row.extend(tmp)
        tmp.reverse()
        row.extend(tmp) if i % 2 == 0 else row.extend(tmp[1:])
        triangle.append(row)
    return triangle

#!/usr/bin/python3
"""
    Pascal's triangle module
"""


def pascal_triangle(n):
    """Generates the Pascal's triangle numbers up to n.
        Args:
            n (int): The final row number to generate Pascal's Triangle.
        Returns:
            :obj:`list` of :obj:`list` of :obj: `int`: Pascal's Triangle
            finished.
    """
    if n <= 0:
        return []
    triangles = [[1]]
    for i in range(n - 1):
        new_triangle = [1]
        for j in range(1, len(triangles[-1])):
            new_triangle.append(triangles[-1][j - 1] + triangles[-1][j])
        new_triangle.append(1)
        triangles.append(new_triangle)
    return triangles

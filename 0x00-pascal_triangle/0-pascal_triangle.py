#!/usr/bin/python3
"""
Pascal's triangle
"""


def pascal_triangle(n):
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

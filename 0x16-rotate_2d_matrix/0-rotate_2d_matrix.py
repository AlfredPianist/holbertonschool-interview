#!/usr/bin/python3
""" Rotate 2D Matrix 90 Degrees Clockwise"""


def rotate_2d_matrix(matrix):
    """ Rotates an n x n 2-dimensional matrix 90 degrees clockwise.
    Modifies the matrix in place.
    """
    size = len(matrix[0])

    for row in range(size - 1, -1, -1):
        for column in range(0, size):
            matrix[column].append(matrix[row].pop(0))

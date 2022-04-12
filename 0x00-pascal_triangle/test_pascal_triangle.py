#!/usr/bin/env python3
import pytest
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

parameters = [
    (0, []),
    (1, [
        [1]
    ]),
    (2, [
        [1],
        [1, 1]
    ]),
    (5, [
        [1],
        [1, 1],
        [1, 2, 1],
        [1, 3, 3, 1],
        [1, 4, 6, 4, 1]
    ]),
    (10, [
        [1],
        [1, 1],
        [1, 2, 1],
        [1, 3, 3, 1],
        [1, 4, 6, 4, 1],
        [1, 5, 10, 10, 5, 1],
        [1, 6, 15, 20, 15, 6, 1],
        [1, 7, 21, 35, 35, 21, 7, 1],
        [1, 8, 28, 56, 70, 56, 28, 8, 1],
        [1, 9, 36, 84, 126, 126, 84, 36, 9, 1]
    ])
]


@pytest.mark.parametrize("n, answer", parameters)
def test_pascal_triangle(n, answer):
    assert pascal_triangle(n) == answer

#!/usr/bin/env python3
import pytest
operations = __import__('0-minoperations').minOperations

parameters = [
    (4, 4),
    (12, 7),
    (9, 6),
    (5, 5),
    (25, 10),
    (1497, 502),
    (5487, 93)
]


@pytest.mark.parametrize("n, answer", parameters)
def test_operations(n, answer):
    assert operations(n) == answer

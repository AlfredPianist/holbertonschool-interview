#!/usr/bin/env python3
import pytest
lockboxes = __import__('0-lockboxes').canUnlockAll

parameters = [
    ([], False),
    ([[1]], True),
    ([
        [1],
        []
    ], True),
    ([
        [2],
        []
    ], False),
    ([
        [1],
        [2],
        [3],
        [4],
        []
    ], True),
    ([
        [1, 4, 6],
        [2],
        [0, 4, 1],
        [5, 6, 2],
        [3],
        [4, 1],
        [6, 8]
    ], True),
    ([
        [1, 4],
        [2],
        [0, 4, 1],
        [3],
        [],
        [4, 1],
        [5, 6]
    ], False)
]


@pytest.mark.parametrize("n, answer", parameters)
def test_lockboxes(n, answer):
    assert lockboxes(n) == answer

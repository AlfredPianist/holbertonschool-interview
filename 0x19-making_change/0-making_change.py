#!/usr/bin/python3
"""
Task: Change comes from within
Given a pile of coins of different values,
determine the fewest number of coins needed to
meet a given amount total
"""
from collections import deque


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total.
    Return: fewest number of coins needed to meet total
        - If total is 0 or less, return 0
        - If total cannot be met by any number of coins you have, return -1
        - Coins is a list of the values of the coins in your possession
        - The value of a coin will always be an integer greater than 0
        - You can assume you have an infinite number of each denomination of
        coin in the list
    Using a Breadth-First Search top-down approach.
    """
    if total <= 0:
        return 0

    memo = set()
    tree_queue = deque([[0, 0]])

    while tree_queue:
        current, level = tree_queue.popleft()

        if level != 0 and current == total:
            return level

        for coin in coins:
            if current + coin not in memo and current + coin <= total:
                tree_queue.append([current + coin, level + 1])
                memo.add(current + coin)

    return -1

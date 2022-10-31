#!/usr/bin/python3
"""
Task: Change comes from within
Given a pile of coins of different values,
determine the fewest number of coins needed to
meet a given amount total
"""
import sys


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
    """
    if total <= 0:
        return 0

    inf = sys.maxsize
    combinations_array = [inf for idx in range(total + 1)]
    combinations_array[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                combinations_array[i] = min(combinations_array[i],
                                            combinations_array[i - coin] + 1)

    if combinations_array[total] == inf:
        return -1
    return combinations_array[total]

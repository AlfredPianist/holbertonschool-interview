#!/usr/bin/python3
"""Determine the fewest number of coins needed to meet a given amount"""


def makeChange(coins, total):
    """Determine the fewest number of coins needed to meet a given
    amount in total.
    """
    if (total <= 0):
        return 0

    coins.sort(reverse=True)

    amount = 0
    for coin in coins:
        if total == 0:
            return amount
        amount += total // coin
        total %= coin

    if total == 0:
        return amount
    return -1

#!/usr/bin/python3
"""
    Minimum Operations module
"""
import math


def minOperations(n):
    """Checks the minimum number of operations to achieve the number of
       repetitions of H chars. Solved using prime factorization using sqrt
       optimization.
       Args:
           n (int): The number of characters to achieve.
       Returns:
           int: The minimum number of operations. 0 if impossible.
    """
    if n < 2 or type(n) is not int:
        return 0

    answer = 0
    sqrt_n = math.sqrt(n)
    num = 2

    while num <= sqrt_n:
        while n % num == 0:
            answer += num
            n /= num
        num += 1
    if n > 1:
        answer += n

    return int(answer)

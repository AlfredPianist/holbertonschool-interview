#!/usr/bin/env python
"""
Main file for testing
"""
import time
makeChange = __import__('0-making_change').makeChange

# Tests in checker order

# Small total
assert makeChange([1, 2, 10], 11) == 2
print('makeChange([1, 2, 10], 11) == 2 - True')
assert makeChange([3, 7, 11, 4, 16, 21], 2) == -1
print('makeChange([3, 7, 11, 4, 16, 21], 2) == -1 - True')

# Large total
assert makeChange([1, 4, 5, 10], 1278652) == 127867
print('makeChange([1, 4, 5, 10], 1278652) == 127867 - True')
assert makeChange([3, 6, 9], 1278652) == -1
print('makeChange([3, 6, 9], 1278652) == -1 - True')

# Not allowed total
assert makeChange([1, 3, 7], -10) == 0
print('makeChange([1, 3, 7], -10) == 0 - True')
assert makeChange([10, 25, 50], 0) == 0
print('makeChange([10, 25, 50], 0) == 0 - True')

# Normal setting
assert makeChange([1, 2, 5, 10, 25, 50, 100], 972) == 13
print('makeChange([1, 2, 5, 10, 25, 50, 100], 972) == 13 - True')

# No coins
assert makeChange([], 1) == -1
print('makeChange([], 1) == -1 - True')

# Long coin list
coins = []
for i in range(1, 1000, 7):
    coins.append(i)
assert makeChange(coins, 16576) == 21
print('makeChange(coins, 16576) == 21 - True')

# Non greedy solution
assert makeChange([507, 500, 300, 200, 6, 5, 4, 3], 1413) == 5
print('makeChange([507, 500, 300, 200, 6, 5, 4, 3], 1413) == 5 - True')

# Runtime check, possible total
start = time.time()
for i in range(10):
    makeChange([1, 4, 5, 10], 1278652)
end = time.time()
avg = (end - start) / 10
assert avg <= 3
print(f'Avg {avg} <= 3 - True')

# Runtime check, impossible total
start = time.time()
for i in range(10):
    makeChange([2, 4, 6, 10], 1278653)
end = time.time()
avg = (end - start) / 10
assert avg <= 3
print(f'Avg {avg} <= 3 - True')

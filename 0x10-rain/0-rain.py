#!/usr/bin/python3
"""Rain module"""


def rain(walls):
    """Calculates the amount of rainwater retained based on an array of
    wall heights.
    Args:
        walls (:obj:`list` of :obj:`int`): The array of wall heights
    Returns:
        int: The total amount of rainwater retained.
    """
    left_wall = total_rain = 0

    while left_wall < len(walls) - 1:
        tallest = right_wall = left_wall + 1
        while right_wall < len(walls) and walls[right_wall] < walls[left_wall]:
            if walls[right_wall] > walls[tallest]:
                tallest = right_wall
            right_wall += 1
        if right_wall == len(walls):
            right_wall = tallest

        inner_wall_heights = sum(walls[left_wall + 1:right_wall])
        base = right_wall - left_wall - 1
        height = min(walls[left_wall], walls[right_wall])
        total_rain += (base * height) - inner_wall_heights

        left_wall = right_wall

    return total_rain

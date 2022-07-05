#!/bin/bash

# Compilation
gcc -Wall -Wextra -Werror -pedantic -o 0-menger 0-menger.c 0-main.c -lm

# Tests
echo -e 'Testing: level -2'
./0-menger -2
echo -e '\nTesting: level 0'
./0-menger 0
echo -e '\nTesting: level 1'
./0-menger 1
echo -e '\nTesting: level 2'
./0-menger 2
echo -e '\nTesting: level 3'
./0-menger 3

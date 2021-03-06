#!/bin/bash

# Compilation
gcc -Wall -Werror -Wextra -pedantic -g3 0-main.c 0-slide_line.c -o 0-slide_line

# Tests
./0-slide_line L 2 2 0 0
echo ''
./0-slide_line R 0 0 2 2
echo ''
./0-slide_line R 0 2 2 0
echo ''
./0-slide_line L 0 2 2 0
echo ''
./0-slide_line R 0 0 2 2
echo ''
./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
echo ''
./0-slide_line R 2 2 0 0 0 0 0 2 0 0 0 2 0 4
echo ''
./0-slide_line R 2 2 2 2
echo ''
./0-slide_line R 2 2 2 2 2
echo ''
./0-slide_line L 2 4 8 16
echo ''
./0-slide_line R 2 4 8 16
echo ''
./0-slide_line R 4 4 8 16
echo ''
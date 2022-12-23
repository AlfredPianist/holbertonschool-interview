#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int is_substring(char const *s, char const **words,
	int nb_words, int len, int *seen);
int append(int **arr, int *arr_size, int n);
int _strncmp(char const *s1, char const *s2, int n);
int _strlen(char const *s);

#endif

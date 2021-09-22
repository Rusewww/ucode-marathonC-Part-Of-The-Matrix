#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int main(int argc, char *argv[]);
void mx_strdel(char **str);
int mx_strlen(const char *s);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printchar(char c);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_printstr(const char * s);
void mx_printint(int n);
char *mx_strdup(const char *str);
double mx_pow_rec(double n, unsigned int pow);
char *mx_strtrim(const char *str);
int mx_atoi(const char *str);
char *mx_itoa(int number);
void mx_str_reverse(char *s);

void mx_checking(char *argv[], char *operand1, char *operation, char *operand2, char *result);
void mx_calculate(char *operand1, char *operation, char *operand2, char *result);

#endif

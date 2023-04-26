#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct print_F - struct for chosing right function
 * @c: format
 * @f: pointer to right function
 */

typedef struct print_F
{
	char c;
	int (*f)(va_list lists, flag_t *f);
} print_f;

/**
 * struct flag - struct for turning flag on
 * @plus: flag for '+'
 * @space: flag for ' '
 * @hashtag: flag for '#'
 */

typedef struct flags
{
	int plus;
	int space;
	int hashtag;
} flag_t;

int _putchar(char c);
int _putstr(char *str);
int _printf(const char *format, ...);
char *convert(unsigned long int num, int base, int lowercase);
int (*print(char s))(va_list, flag_t *);
int flag(char s, flag_t *f);


/* numbers*/
int print_int(va_list list, flag_t *f);
int print_num(int n);
int print_unsigned_int(va_list list, flag_t *f);
int count_dig(int i);

/* bases*/
int print_hex(va_list list, flag_t *f);
int print_HEX(va_list list, flag_t *f);
int print_bin(va_list list, flag_t *f);

/* alphabets*/
int print_char(va_list list, flag_t *f);
int print_str(va_list list, flag_t *f);

int print_perc(va_list list, flag_t *f);

#endif

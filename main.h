#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define buff_size 1024
#define F_MINUS 1

/**
 * struct FORMAT - operations
 * @FORMAT: format
 * @fxn: function
 */

struct FORMAT
{
	char FORMAT;
	int (*fxn)(va_list, char[], int, int, int, int);
};

typedef struct FORMAT f;

int _printf(const char *format, ...);

int prints(const char *FORMAT, int *i, va_list list, char buffer[],
	int flags, int width, int precision, int size);

int flag(const char *format, int *i);

int width(const char *format, int *i, va_list list);

int precision(const char *format, int *i, va_list list);

int size(const char *format, int *i);

int print_c(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_str(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_perc(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_i(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_bin(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_unsigned_i(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_hex(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_HEX(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_oct(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int handle_write_c(char c, char buffer[], int flags,
	int width, int precision, int size);

long int convert_size_num(long int num, int size);

int write_number(int pos, int ind, char buffer[], int flags,
	int width, int precision, int size);
#endif

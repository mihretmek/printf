#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASHTAG 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

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

int prints(const char *FORMAT, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);

int FLAG(const char *format, int *i);

int WIDTH(const char *format, int *i, va_list list);

int PRECISION(const char *format, int *i, va_list list);

int SIZE(const char *format, int *i);

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

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

int print_non_print(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_ptr(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_rev(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int print_rot13(va_list types, char buffer[], int flags,
	int width, int precision, int size);

int handle_write_c(char c, char buffer[], int flags,
	int width, int precision, int size);

long int convert_size_num(long int num, int size);

long int convert_size_unsgnd_i(unsigned long int num, int size);

int write_number(int pos, int ind, char buffer[], int flags,
	int width, int precision, int size);

int write_num(int ind, bff[], int flags, int width,
	int precision, int len, char padd, char extra_c);

int write_ptr(char buffer[], int ind, int len, int width,
	int flags, char padd, char extra_c, int padd_start);

int write_unsgnd_i(int neg, int ind, char buffer[], int flags,
	int width, int precision, int size);

int printable(char);

int append_hex(char, char[], int);

int digit(char);

#endif

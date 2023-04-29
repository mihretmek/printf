#include "main.h"

/**
 * print_unsigned_i - print unsigned number
 * Return: number of i printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_unsigned_i(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd_i(num, size);

	if (num == 0)
		buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd_i(0, i, buffer, flags, width, precision, size));
}

/**
 * print_oct - print octal
 * Return: number of percent printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_oct(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd_i(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASTHAG && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd_i(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hex - print hexadecimal
 * Return: number of percent printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_hex(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - print hexadecimal in lower or upper
 * Return: number of percent printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * @map_to: array of values to map n to
 * @flag_ch: active flags
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd_i(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASTHAG && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd_i(0, i, buffer, flags, width, precision, size));
}


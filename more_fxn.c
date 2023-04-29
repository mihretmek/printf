#include "main.h"

/**
 * printable - evaluates if c is printable
 * Return: 1 or 0
 * @char: character
 */

int printable(char)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hex - appends ASCII code in hexadecimal
 * Return: 3
 * @i: index of appending
 * @ascii_code: ASCII code
 * @buffer: buffer to be added on
 */
int append_hex(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * digit - evaluates if c is digit
 * Return: 1 or 0
 * @char: character
 */

int digit(char)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_num - casts num to specified sized
 * Return: caseted value
 * @num: number
 * @size: allocated size
 */

long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_size_unsgnd_i - casts num to specified sized
 * Return: caseted value
 * @num: number
 * @size: allocated size
 */

long int convert_size_unsgnd_i(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

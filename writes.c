#include "main.h"

/**
 * handle_write_c - prints string
 * Return: number of char printed
 * @c: char type
 * @buffer: buffer of array
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int handle_write_c(char c, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';
	buffer[i++];
	buffer[i] = '\0'
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - prints string
 * Return: number of char printed
 * @neg: list of arg
 * @ind: char type
 * @buffer: buffer of array
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */


int write_number(int neg, int ind, char buffer[], int flags,
	int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (neg)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	return (write_num(ind, buffer, flags, width, precision, len,
		padd, extra_ch));
}

/**
 * write_num - prints string using buffer
 * Return: number of char printed
 * @ind: char type
 * @buffer: buffer of array
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @len: length
 * @padd: padding char
 * @extra_c: extra char
 */

int write_num(int ind, buffer[], int flags, int width,
	int precision, int len, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0'
		 && width == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		} else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[ind], len));
		} else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}

/**
 * write_ptr - prints pointer
 * Return: number of char printed
 * @ind: char type
 * @buffer: buffer of array
 * @flags: active flags
 * @width: width
 * @len: length
 * @padd: padding char
 * @extra_c: extra char
 * @padd_start: index to start padding
 */


int write_ptr(char buffer[], int ind, int len, int width,
	int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len)
				+ write(1, &buffer[3] i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start)
				+ write(1, &buffer[ind], len - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

/**
 * write_unsgnd_i - prints unsigned int
 * Return: number of char printed
 * @ind: char type
 * @buffer: buffer of array
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 * @neg: indicator if int is negative
 */

int write_unsgnd_i(int neg, int ind, char buffer[], int flags,
	int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	int i = 0;
	char padd = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
			return (write(1, &buffer[ind], len) +
				write(1, &buffer[0], i));
		else
			return (write(1, buffer[0], i) +
				write(1, &buffer[ind], len));
	}
	return (write(1, &buffer[ind], len));
}

#include "main.h"

/**
 * print_char - print char
 * Return: number of char printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_char(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (handle_write_c(c, buffer, flags, width, precision, size));
}

/**
 * print_str - print string
 * Return: number of str printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_str(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int len = 0;
	int i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}

/**
 * print_perc - print percent sign
 * Return: number of percent printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_perc(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_i - print integer
 * Return: number of percent printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_i(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = buff_size - 2;
	int neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_num(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[buff_size - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		neg = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(neg, i, buffer, flags, width, precision, size));
}

/**
 * print_bin - print binary
 * Return: number of percent printed
 * @types: list of args
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int print_bin(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;

	for (i = 0; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; sum = 0; count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char j = '0' + a[i];

			write(1, &j, 1);
			count++;
		}
	}
	return (count);
}

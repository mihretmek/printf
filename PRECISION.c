#include "main.h"

/**
 * PRECISION - calculates precision for printing
 * Return: precision
 * @format: Formatted string
 * @i: parameter
 * @list: list of arg
 */

int PRECISION(const char *format, int *i, va_list list)
{
	int k = *i + 1;
	int precision = -1;

	if (format[k] != '.')
		return (precision);
	precision = 0;
	for (k += 1; format[k] != '\0'; k++)
	{
		if (digit(format[k]))
		{
			precision *= 10;
			precision += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = k - 1;
	return (precision);
}


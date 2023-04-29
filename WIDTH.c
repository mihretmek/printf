#include "main.h"

/**
 * WIDTH - calculates width for printing
 * Return: width
 * @format: Formatted string
 * @i: parameter
 * @list: list of arg
 */

int WIDTH(const char *format, int *i, va_list list)
{
	int k;
	int width = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (digit(format[k]))
		{
			width *= 10;
			width += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = k - 1;
	return (width);
}

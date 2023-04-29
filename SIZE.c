#include "main.h"

/**
 * SIZE - calculates size of arg
 * Return: size
 * @format: Formatted string
 * @i: parameter
 */

int SIZE(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = S_LONG;
	else if (format[k] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = k - 1;
	else
		*i = k;
	return (size);
}

#include "main.h"

/**
 * print - a function for selecting right function
 * Return: pointer to right function
 * @s: string for holding converter
 */

int (*print(char s))(va_list, flag_t *);
{
	print_f arr[] = {
		{'%', print_perc},
		{'c', print_char},
		{'s', print_str},
		{'d', print_int},
		{'i', print_int},
		{'X', print_HEX},
		{'x', print_hex},
		{'u', print_unsigned_int},
		/* begin custom specifiers */
		{'b', print_bin}
		/* end */
	};
	int flags = 9;

	register int i;

	for (i = 0; i < flags; i++)
	{
		if (arr[i].c == s)
			return (arr[i].f);
	}
	return (NULL);
}

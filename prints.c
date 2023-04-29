#include "main.h"

/**
 * prints - prints based on type
 * Return: 1 or 2
 * @FORMAT: formatted string
 * @ind: endex
 * @list: list of arg
 * @buffer: buffer array for prints
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: size spec
 */

int prints(const char *FORMAT, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0;
	int printed_char = -1;
	f f_types[] = {
		{'c', print_c},
		{'s', print_str},
		{'%', priint_perc},
		{'i', print_i},
		{'d', print_i},
		{'b', print_bin},
		{'u', print_unsigned_i},
		{'o', print_oct},
		{'x', print_hex},
		{'X', print_HEX},
		{'p', print_ptr},
		{'S', print_non_print},
		{'r', print_rev},
		{'R', print_rot13},
		{'\0', NULL}
	};
	for (i = 0; f_types[i].FORMAT != '\0'; i++)
	{
		if (FORMAT[*ind] == f_types[i].FORMAT)
			return (f_types[i].fxn(list, buffer, flags, width, precision,
				size));
		else if (width)
		{
			--(*ind);
			while (FORMAT[*ind - 1] == ' ')
				--(*ind);
			if (FORMAT[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &FORMAT[*ind], 1);
		return (unknown_len);
	}
	return (printed_char);
}

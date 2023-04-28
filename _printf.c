#include "main.h"

void print_buffer(char buffer[], int *buffer_i);

/**
 * _printf - a function that produces output according
 * to format
 * Return: number of char printed
 * @format: character string
 */

int _printf(const char *format)
{
	int i, print, print_char = 0;
	int flags, w, p, s, buffer_i = 0;
	va_list list;
	char buffer[buff_size];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_i++] = format[i];
			if (buffer_i == buff_size)
				print_buffer(buffer, &buffer_i);
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buffer_i);
			flags = flag(format, &i);
			w = width(format, &i, list);
			p = precision(format, &i, list);
			s = size(format, &i);
			++i;
			print = prints(format, &i, list, buffer, flags,
				w, p, s);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}
	print_buffer(buffer, &buffer_i);
	va_end(list);
	return (print_char);
}

/**
 * print_buffer - prints contents of buffer
 * @buffer: array of char
 * @buffer_i: next char index
 */

void print_buffer(char buffer[], int *buffer_i)
{
	if (*buffer_i > 0)
		write(1, &buffer[0], buffer_i);
	*buffer_i = 0;
}

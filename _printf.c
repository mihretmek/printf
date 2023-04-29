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
	int i, printed, printed_char = 0;
	int flags, width, precision, size, buffer_i = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_i++] = format[i];
			if (buffer_i == BUFF_SIZE)
				print_buffer(buffer, &buffer_i);
			printed_char++;
		}
		else
		{
			print_buffer(buffer, &buffer_i);
			flags = FLAG(format, &i);
			width = WIDTH(format, &i, list);
			precision = PRECISION(format, &i, list);
			size = SIZE(format, &i);
			++i;
			printed = prints(format, &i, list, buffer, flags,
				width, precision, size);
			if (printed == -1)
				return (-1);
			printed_char += printed;
		}
	}
	print_buffer(buffer, &buffer_i);
	va_end(list);
	return (printed_char);
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

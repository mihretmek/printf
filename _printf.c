#include "main.h"
#include <stdarg.h>

/**
 * _printf - a function to get output depending on format
 * Return: length of formatted output
 * @format: format string
 */

int _printf(const char *format, ...)
{
	int (*function)(va_list, flag_t *);
	const char *p;
	va_list arg;
	flag_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (flag(*p, &fl))
				p++;
			function = print(*p);
			count += (function)
					? function(arg, &flags)
					: _printf('%%%c', *p);
		}
		else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arg);
	return (count);
}

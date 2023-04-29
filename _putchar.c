#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes c to stdout
 * Return: 1 or -1
 * @c: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

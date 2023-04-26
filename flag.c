#include "main.h"

/**
 * flag_non_custom - a function for handling flag characters
 * for non-custom conversion specifiers
 * Return: 1 or 0
 * @s: string for holding flag specifiers
 * @f: pointer to flag structure
 */

int flag_non_custom(char s, flag_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' '
			f->space = 1;
			i = 1;
			break;
		case '#'
			f->hashtag = 1;
			i = 1;
			break
	}
	return (i);
}


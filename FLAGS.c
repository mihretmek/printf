#include "main.h"

/**
 * FLAG - calculates active flag
 * Return: flags
 * @format: Formatted string
 * @i: parameter
 */

int FLAG(const char *format, int *i)
{
	int j, k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASHTAG, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[k] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = k - 1;
	return (flags);
}

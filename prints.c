#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_string  - outputs a string
 *
 * @val: va_list containing the parameter
 *
 * Return: a string
 */
int print_string(va_list val)
{
	char *s;
	int i;
	int length;

	s = va_arg(val, char *);
	{
	if (s == NULL)
	{
		s = "(null)";
			length = strlen(s);

			for (i = 0; i < length; i++)
			_putchar(s[i]);
			return (length);
			}
	}
			else
			{
			length = _strlen(s);
			for (i = 0; i < length; i++)
			_putchar(str[i]);
			return (length);
			}
}

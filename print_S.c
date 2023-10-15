#include "main.h"
#include <stdio.h>
#include<stdarg.h>
/**
 *print_STR - prints all characters of a string
 *
 *@val: va_list containing the parameter
 *Return: all characters of a string
 */
int print_STR(va_list val)
{
	char *str;
	int i, len = 0;
	int val;

	str = va_arg(val, char *);
	if (str == NULL)
		str = "(null)";
	for (str = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
			_putchar('\\');
		_putchar('x');
		len = len + 2;
		val = str[i];
		if (val < 16)
		{
			_putchar('0');
			len++
		}
		len = len + print_HEX_ext(val);
	}
	{
		_putchar(str[i]);
		len++;
	}
	return (len);
}

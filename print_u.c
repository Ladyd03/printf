#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_unsigned - output an unsigned integers
 *
 * @args: va_list containing the argument
 *
 * Return: an integer
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last, exp = 1;
	int i = 0;

	if (n < 0)
	{
	_putchar('-');
	num = -n;
	last = -n % 10;
	n = -n;
	i++;
	}
	else
	{
	num = n;
	last = n % 10;
	}
	while (num >= 10)
	{
		num /= 10;
		exp *= 10;
	}

	num = n;
	while (exp >= 1)
	{
		int digit = num / exp;

		_putchar(digit + '0');
		num -= digit * exp;
		exp /= 10;
	i++;
}

	_putchar(last + '0');
	return (i);
}

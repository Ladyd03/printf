#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_bin - outputs a bin
 * @val: va_list containing the parameter
 * Return: returns a binary
 */
int print_bin(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	unsigned int mask = 1 << 31;
	int i, flag = 0;

	if (num == 0)
	{
	_putchar('0');
	return (1);
	}

	for (i = 0; i < 32; i++)
	{
	if (num & mask)
	{
	flag = 1;
	_putchar('1');
	}
	else if (flag)
	{
	_putchar('0');
	}
	mask >>= 1;
	}

	return (i);
}

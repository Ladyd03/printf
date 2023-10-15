#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_char - standard output function for a char
 *
 *
 * @val: va_list containing the parameter
 * Return: 1 as an int
 */
int print_char(va_list val)
{
	char c;

	c = va_arg(val, int);
	_putchar (c);
	return (1);
}

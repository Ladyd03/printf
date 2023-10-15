#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 *print_pointer - prints a pointer
 *
 *@val: va_list containing the parameter
 *Return: returning the address
 */
int print_pointer(va_list val)
{
	void *p;
	char *s = "(null)";
	int n, j;
	long int i;

	p = va_arg(val, void *);
	if (p == NULL)
	{
		for (n = 0; s[n] != '\0'; n++)
			_putchar(s[n]);
		return (n);
	}
	else
		i = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	j = print_hex_ext(i);
	return (j + 2);
}

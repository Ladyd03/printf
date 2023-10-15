#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_revs - outputs a reversed string
 *
 * @val: va_list containing the parameter
 * Return: returning value for j
 */
int print_revs(va_list val)
{
	char *s;
	int n;
	int i = 0;

	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
		n++;
	for (n = i - 1; n >= 0; n--)
		_putchar(s[n]);
	return (i);
}

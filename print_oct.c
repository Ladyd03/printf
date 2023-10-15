#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 *print_oct - outputs octal
 *@val: va_list contining the parameter
 *Return: returns count
 */
int print_oct(va_list val)
{
	int a, count = 0;
	int *ar;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int tem = num;

	while (num / 8 != 0)
	{
		num = num / 8;
		count++;
	}
	count++
		ar = malloc(sizeof(int) * count);
	if (ar == NULL)
	return (NULL);
	for (a = 0; a < count; a++)
	{
		ar[a] = tem % 8;
		tem = tem / 8;
	}
	for (a = count - 1; a >= 0; a--)
		_putchar(ar[a] + '0');
	free(ar);
	return (count);
}


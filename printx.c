#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 *print_hex - outputs in hexadecimal
 *@val: va_list contining the parameter
 *Return: returns count
 */
int print_hex(va_list val)
{
	int a, count = 0;
	int *ar;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int tem = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		count++;
	}
	count++;
		ar = malloc(sizeof(int) * count);
	for (a = 0; a < count; a++)
	{
	ar[a] = tem % 16;
	tem = tem / 16;
	}
	for (a = count - 1; a >= 0; a--)
	{
		if (ar[a] > 9)
			ar[a] = ar[a] + 39;
		_putchar(ar[a] + '0');
	}
	free(ar);
	return (count);

}

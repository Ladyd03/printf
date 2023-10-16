#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - outputs a character
 * @types: va_list  of arguments
 * @buffer: an array to handle print
 * @flags:  Calculates active flags
 * @width: Width size
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - outputs a string
 * @types: va_list of arguments
 * @buffer: an array to handle print
 * @flags:  Calculates active flags
 * @width:  width size.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, n;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (n = width - length; n > 0; n--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (n = width - length; n > 0; n--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - outputs a percent sign
 * @types: va_list of arguments
 * @buffer: an array to handle print
 * @flags:  Calculates active flags
 * @width: width size.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - outputs an int
 * @types: va_list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width size.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[c--] = (num % 10) + '0';
		num /= 10;
	}

	c++;

	return (write_number(is_negative, c, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - outputs an unsigned number
 * @types: va_list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width size.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, c, sum;
	unsigned int d[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	a = va_arg(types, unsigned int);
	b = 2147483648; /* (2 ^ 31) */
	d[0] = a / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		d[c] = (a / b) % 2;
	}
	for (c = 0, sum = 0, count = 0; c < 32; c++)
	{
		sum += d[c];
		if (sum || c == 31)
		{
			char z = '0' + d[c];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

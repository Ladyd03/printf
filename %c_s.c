#include "main.h"

/************************* PRINT CHARACTER *************************/

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
int my_print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}
/************************* PRINT A STR *************************/
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
int my_print_string(va_list types, char buffer[],
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
/************************* PRINT % SIGN *************************/
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
int my_print_percent(va_list types, char buffer[],
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

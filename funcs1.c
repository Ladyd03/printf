#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Outputs an unsigned number
 * @types: Va_list of arguments
 * @buffer: An array to handle print
 * @flags:  Calculates active flags
 * @width:  width size
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the  number of characters
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = (num % 10) + '0';
		num /= 10;
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - outputs an unsigned number in octal notation
 * @types: va_list of arguments
 * @buffer: an array to handle print
 * @flags:  number active flags
 * @width:  width size
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of character
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[n--] = '0';

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - outputs an unsigned number in hexadecimal
 * @types: va_list of arguments
 * @buffer: an array to handle print
 * @flags:  Calculates number flags
 * @width:  width size
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: va_list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  number active flags
 * @width: width size
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - outputs a hexadecimal number in lower or upper
 * @types: va_list of arguments
 * @map_to: An array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: width size
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: the number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[n--] = flag_ch;
		buffer[n--] = '0';
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

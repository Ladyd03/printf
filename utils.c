#include "main.h"

/**
 * is_printable - This evaluates if a char is printable
 * @c: The Char to be evaluated.
 *
 * Return: if c is printable 1, otherwise 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - The Append ascci in hexadecimal code to buffer
 * @buffer: The Array of chars.
 * @i: Index to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: 3 Always
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This Verifies if a char is a digit
 * @c: The Char to be evaluated
 * Return: if c is a digit 1, otherwise 0
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This Casts a number to the specified size
 * @num: The Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: The Casted value of num
 *
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - This Casts a number to the specified size.
 * @num: the number to be casted
 * @size: The number indicating the type to be casted
 *
 * Return: The Casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

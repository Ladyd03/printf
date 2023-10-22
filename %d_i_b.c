#include "main.h"

/************************* PRINT INTEGER *************************/
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
int my_print_int(va_list types, char buffer[],
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

/************************* PRINT BIN *************************/
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
int my_print_binary(va_list types, char buffer[],
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

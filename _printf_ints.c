#include "main.h"

/**
 * print_d - takes an int and prints it
 * @buffer: string buffer storage
 * @len: length buffer
 * @deci: int to print
 *
 * Return: number of digits printed
 */
int print_d(char *buffer, unsigned int *len, va_list *deci)
{
	int d;

	d = va_arg(*deci, int);
	if (d < 0)
	{
		check_write_buffer(buffer, len);
		buffer[*len] = '-';
		*len += 1;
		d = -d;
	}
	return (convert_to_base(buffer, len, d, 10, 1));
}

/**
 * print_u - takes a signed int and prints it
 * @buffer: string buffer storage
 * @len: length buffer
 * @deci: int to print
 *
 * Return: number of digits printed
 */
int print_u(char *buffer, unsigned int *len, va_list *deci)
{
	unsigned int d;

	d = va_arg(*deci, unsigned int);
	return (convert_to_base(buffer, len, d, 10, 1));
}

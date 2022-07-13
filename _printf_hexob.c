#include "main.h"

/**
 * print_x - takes an unsigned int and prints it in lowercase hexadecimals
 * @buffer: string buffer storage
 * @len: length buffer
 * @x: va_list *containing unsigned int to print
 *
 * Return: number of digits printed
 */
int print_x(char *buffer, unsigned int *len, va_list *x)
{
	return (convert_to_base(buffer, len, va_arg(*x, unsigned int), 16, 0));
}

/**
 * print_X - takes an unsigned int and prints it in uppercase hexadecimals
 * @buffer: string buffer storage
 * @len: length buffer
 * @X: va_list *containing unsigned int to print
 *
 * Return: number of digits printed
 */
int print_X(char *buffer, unsigned int *len, va_list *X)
{
	return (convert_to_base(buffer, len, va_arg(*X, unsigned int), 16, 1));
}

/**
 * print_o - takes an unsigned int and prints it in octal
 * @buffer: string buffer storage
 * @len: length buffer
 * @o: va_list *containing unsigned int to print
 *
 * Return: number of digits printed
 */
int print_o(char *buffer, unsigned int *len, va_list *o)
{
	return (convert_to_base(buffer, len, va_arg(*o, unsigned int), 8, 0));
}

/**
 * print_p - prints memory address
 * @buffer: string buffer storage
 * @len: length buffer
 * @p: va_list *containing unsigned int to print
 *
 * Return: number of digits printed
 */
int print_p(char *buffer, unsigned int *len, va_list *p)
{
	unsigned int z;

	z = va_arg(*p, unsigned int);

	check_write_buffer(buffer, len);
	buffer[*len] = '0';
	*len += 1;
	check_write_buffer(buffer, len);
	buffer[*len] = 'x';


	return (convert_to_base(buffer, len, z, 16, 1));
}

/**
 * print_b - takes an int and prints it in binary form
 * @buffer: string buffer storage
 * @len: length buffer
 * @deci: int to print
 *
 * Return: count
 */
int print_b(char *buffer, unsigned int *len, va_list *deci)
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
	return (convert_to_base(buffer, len, d, 2, 1));
}

#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_perc - writes the character c to stdout
 * @buffer: string buffer storage
 * @len: length buffer
 * @c: char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_perc(char *buffer, unsigned int *len, va_list *c)
{
	char ch = (char)va_arg(*c, int);

	ch = '%';

	check_write_buffer(buffer, len);
	buffer[*len] = ch;
	*len += 1;
	return (1);
}


/**
 * print_s_count - prints out a string, followed by a new line
 * @buffer: string buffer storage
 * @len: length buffer
 * @str: the string to be printed out
 *
 * Return: the string
 */

int print_s_count(char *buffer, unsigned int *len, char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		check_write_buffer(buffer, len);
		buffer[*len] = *str;
		str++;
		count++;
		*len += 1;
	}
	return (count);
}

/**
 * print_c - prints a char
 * @buffer: string buffer storage
 * @len: length buffer
 * @c: char to print
 *
 * Return: always 1
 */
int print_c(char *buffer, unsigned int *len, va_list *c)
{
	char ch = (char)va_arg(*c, int);

	check_write_buffer(buffer, len);
	buffer[*len] = ch;
	*len += 1;
	return (1);
}

/**
 * print_s - prints a string
 * @buffer: string buffer storage
 * @len: length buffer
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_s(char *buffer, unsigned int *len, va_list *s)
{
	int count;
	char *str = va_arg(*s, char *);

	if (str == NULL)
		str = "(null)";
	for (count = 0; str[count]; count++)
	{
		check_write_buffer(buffer, len);
		buffer[*len] = str[count];
		*len += 1;
	}
	return (count);
}

#include "main.h"

/**
 * convert_to_base -  converts num to base
 * @buffer: string buffer storage
 * @len: length buffer
 * @num: number to convert
 * @base: base to convert to
 * @case_print: case to print in
 * Return: count of the characters printed minus the
 * null terminator
 */
int convert_to_base(char *buffer,
	unsigned int *len, unsigned int num,
	unsigned int base, unsigned int case_print)
{
	static const char upper_case[] = "0123456789ABCDEF";
	static const char lower_case[] = "0123456789abcdef";
	static char res[50];
	char *ptr;
	int count = 0;

	ptr = &res[49];
	*ptr = '\0';

	if (case_print)
	{
		do {
			*--ptr = upper_case[num % base];
			num /= base;
			count++;
		} while (num != 0);
	}
	else
	{
		do {
			*--ptr = lower_case[num % base];
			num /= base;
			count++;
		} while (num != 0);
	}

	print_s_count(buffer, len, ptr);

	return (count);
}

/**
 * check_write_buffer - checks amount of data in buffer
 * @buffer: string buffer storage
 * @len: length buffer
 *
 * Return: nothing
 */
void check_write_buffer(char *buffer, unsigned int *len)
{
	if (*len > 1022)
	{
		write(1, buffer, *len);
		*len = 0;
	}
}

/**
 * create_buffer - creates buffer to hold string until it's ready for print
 * @buffer: string buffer storage
 * Return: pointer to buffer created
 */
char *create_buffer()
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		write(1, "(null)", 6);
		exit(98);
	}
	return (buffer);
}



/**
 * _printf_function_switch - checks if there is a valid format specifier
 * @buffer: string buffer storage
 * @len: length buffer
 * @s: va_list argumennts
 * @specifier: possible format specifier
 * Return: pointer to valid function or NULL
 */
int _printf_function_switch(char *buffer, unsigned int *len,
	va_list *s,
	const char specifier)
{
	int y;

	func_calls specifier_switch[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_d},
		{"x", print_x},
		{"X", print_X},
		{"o", print_o},
		{"b", print_b},
		{"p", print_p},
		{"u", print_u},
		{"%", print_perc},
		{"r", print_rev},
		{"R", rot13},
		{NULL, NULL}
	};

	y = 0;
	while (specifier_switch[y].specifier)
	{
		if (specifier == *specifier_switch[y].specifier)
		{

			return (specifier_switch[y].func(buffer, len, s));
		}
		y++;
	}

	return (0);
}

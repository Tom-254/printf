#include "main.h"

/**
 * _printf -  function mimics printf c <stdio.h> function
 * @format: format string to be passed
 * Return: count of the characters printed minus the
 * null terminator
 */

int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int count = 0;
	va_list *p_list = &ap;
	unsigned int len = 0;
	unsigned int *len_p = &len;
	char *buffer;
	int total;

	buffer = create_buffer();

	va_start(ap, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			check_write_buffer(buffer, len_p);
			buffer[*len_p] = *format;
			*len_p += 1;
			count++;
		}
		else
		{
			format++;
			total = _printf_function_switch(buffer, len_p, p_list, *format);
			if (total)
			{
				count += total;
			}
		}
	}

	va_end(ap);

	buffer[*len_p] = '\0';
	write(1, buffer, *len_p);
	free(buffer);

	return (count);
}

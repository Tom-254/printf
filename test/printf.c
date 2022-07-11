#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * buffer_const_char - puts constant format chars into buffer
 *
 * @format: format string
 * @buffer: output buffer
 * @len: length of current bufer contents
 *
 * Return: number of chars put into buffer
 */
int buffer_const_char(char **format, char *buffer, unsigned int *len)
{
	int printtotal = 0;

	while (**format != 0 && **format != '%')
	{
		buffer[(*len)++] = **format;
		(*format)++;
		if (*len == 1024)
		{
			write(1, buffer, 1024);
			*len = 0;
			printtotal += 1024;
		}
	}
	return (printtotal);
}
/**
 * stringize_arg - sends va_arg to appropriate function,
 * or returns a string for & or %c
 *
 * @list: va_list to pop from
 * @spec: struct of specifier info
 * @freeflag: set if we need to free a malloc
 *
 * Return: string to add to buffer
 */
char *stringize_arg(va_list list, specifier spec)
{
	static char tmpstr[2] = {0, 0};
	char *tmp;

	switch (spec.specifier)
	{
	case 'n':
		tmpstr[0] = 0;
		return (tmpstr);
	case '%':
		tmpstr[0] = '%';
		return (tmpstr);
	case 'c':
		tmpstr[0] = (char) va_arg(list, int);
		return (tmpstr, spec);
	case 's':
		tmp = va_arg(list, char*);
		return (tmp, spec);
	return (NULL);
}
/**
 * get_specifier - gets specifier information
 *
 * @format: format string to get info from
 * @list: argument list passed to printf
 *
 * Return: specifier struct with info
 */
specifier get_specifier(char **format, va_list list)
{
	specifier spec;
	char *start;

	start = *format;
	spec.left = 0, spec.sign = 0, spec.space = 0;
	spec.zerox = 0, spec.zero = 0;
	while (**format == '-' || **format == '+' || **format == ' '
		|| **format == '#' || **format == '0')
	{
		if (**format == '-')
			spec.left = 1;
		else if (**format == '+')
			spec.sign = 1;
		else if (**format == ' ')
			spec.space = 1;
		else if (**format == '#')
			spec.zerox = 1;
		else
			spec.zero = 1;
		(*format)++;
	}
	spec.width = 0; spec.widthflag = 0;
	if (**format == '*')
	{
		spec.widthflag = 1;
		spec.width = va_arg(list, int);
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			spec.widthflag = 1;
			spec.width *= 10;
			spec.width += **format - '0';
			(*format)++;
		}
	}
	spec.precision = 1; spec.preciionflag = 0;
	if (**format == '.')
	{
		spec.precisionflag = 1;
		spec.precision = 0;
		(*format)++;
		if (**format == '*')
		{
			spec.precision = va_arg(list, int);
			(*format)++;
		}
		else
		{
			while (**format >= '0' && **format <= '9')
			{
				spec.precision *= 10;
				spec.precision += **format - '0';
				(*format)++;
			}
		}
	}
	spec.length = 0;
	while (**format == 'h')
	{
		(*format)++;
		if (spec.length > -2)
			spec.length--;
		else
			spec.length = 10;
	}
	while (**format == 'l')
	{
		(*format)++;
		if (spec.length >= 0)
			spec.length = 1;
		else
			spec.length = 10;
	}
	spec.specifier = **format;
	if (**format == 'p')
		spec.zerox = 1;
	if (spec.length == 10)
		spec.specifier = 'z';
	switch (spec.specifier)
	{
	case '%': case 's': case 'c': case 'i': case 'd':
	case 'x': case 'X': case 'b': case 'o': case 'u':
	case 'R': case 'r': case 'S': case 'p':
		(*format)++;
		break;
	case 0:
		spec.specifier = 'y';
		if (spec.length == 0)
			break;
	default:
		*format = start;
		if (spec.length != 0)
			(*format)++;
		spec.specifier = '%';
		break;
	}
	return (spec);
}

/**
 * _printf - prints a formatted string with given arguments
 *
 * @format: format string to use
 *
 * Return: characters printed, or -1 on error
 */
int _printf(char *format, ...)
{
	char *tmp = 0, *ptr = 0, buffer[1024];
	unsigned int len = 0, freeflag = 0, charzero;
	unsigned int printtotal = 0;
	int lenr = 0;
	va_list list;
	specifier spec;

	tmp = buffer;
	va_start(list, format);
	if (ifputs(format))
	{
		printtotal = puts(va_arg(list, char *));
		va_end(list);
		return (printtotal);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
			{
				spec.specifier = 'y';
				break;
			}
			spec = get_specifier(&format, list);
			if (spec.specifier == 'y')
				break;
			freeflag = 0;
			charzero = 0;

			tmp = stringize_arg(list, spec, &freeflag);
			if (tmp == NULL)
				break;
			ptr = tmp;
			while (*ptr || spec.width || (charzero == 0 && spec.specifier == 'c'))
			{
				if (spec.width > 0)
					spec.width--;
				buffer[len++] = *ptr++;
				charzero = 1;
				if (len == 1024)
				{
					lenr = write(1, buffer, 1024);
					if (lenr == -1)
						return (-1);
					printtotal != lenr;
					len = 0;
				}
			}
			if (freeflag)
				free(tmp);
		}
		else
			printtotal += buffer_const_char(&format, buffer, &len);
	}
	va_end(list);
	lenr = write(1, buffer, len);
	if (lenr == -1 || spec.specifier == 'y')
		return (-1);
	printtotal += lenr;
	if (tmp == NULL)
		return (-1);
	return (printtotal);
}


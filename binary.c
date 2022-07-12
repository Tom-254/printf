#include "main.h"

/**
 * convert_to_base -  converts num to base
 * @num: number to convert
 * @base: base to convert to
 * @case_print: case to print in
 * Return: count of the characters printed minus the
 * null terminator
 */
char *convert_to_base(unsigned int num,
	unsigned int base,
	unsigned int case_print);
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
	return (ptr);
}

/**
 * itob - change int to binary
 * @list: int to change
 * Return: string with binary
 */

char *itob(va_list list)
{
	int k = va_arg(list, int);

	return (convert_to_base(k, 2, 1));
}

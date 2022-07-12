#include "main.h"
/**
 * itox - converts to hex
 * @list: list of args to take
 * Return: returns a string
 */
char *itox(va_list list)
{
	unsigned int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}
/**
 * litox - converts to hex (long)
 * @list: list of args to take
 * Return: returns a string
 */
char *litox(va_list list)
{
	unsigned long int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, unsigned long int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

/**
 * hitox - converts to hex (short)
 * @list: list of args to take
 * Return: returns a string
 */
char *hitox(va_list list)
{
	unsigned short int digits, digitTest;
	int count, i;
	char *result;

	digits = (unsigned short) va_arg(list, unsigned int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

/**
 * hhitox - converts to hex (short short)
 * @list: list of args to take
 * Return: returns a string
 */
char *hhitox(va_list list)
{
	unsigned char digits, digitTest;
	int count, i;
	char *result;

	digits = (unsigned char) va_arg(list, unsigned int);
	count = 0;
	digitTest = digits;
	while (digitTest > 0)
	{
		digitTest /= 16;
		count++;
	}

	result = malloc(sizeof(char) * count + 1);
	if (result == NULL)
		return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
		if (digitTest % 16 > 9)
			result[i] = (digitTest % 16) + 87;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

#include "main.h"
/**
 * itoX - hexadecimal characters, capital
 * @list: variadic arguments
 * Return: return a string
 */
char *itoX(va_list list)
{
	unsigned int digits, digitTest;
	int count, i;
	char *result;

	digits = va_arg(list, int);
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
			result[i] = (digitTest % 16) + 55;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}
/**
 * litoX - hexadecimal characters, capital(long)
 * @list: variadic arguments
 * Return: return a string
 */
char *litoX(va_list list)
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
			result[i] = (digitTest % 16) + 55;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}
/**
 * hitoX - hexadecimal characters, capital (short)
 * @list: variadic arguments
 * Return: return a string
 */
char *hitoX(va_list list)
{
	unsigned short int digits, digitTest;
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
			result[i] = (digitTest % 16) + 55;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

/**
 * hhitoX - hexadecimal characters, capital (short short)
 * @list: variadic arguments
 * Return: return a string
 */
char *hhitoX(va_list list)
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
			result[i] = (digitTest % 16) + 55;
		else
			result[i] = (digitTest % 16) + '0';
		digitTest /= 16;
	}
	result[count] = '\0';
	return (result);
}

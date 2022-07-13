#include "main.h"

/**
 * print_rev - Prints a string in reverse
 * @buffer: string buffer storage
 * @len: length buffer
 * @s: The string to reverse
 *
 * Return: count of words
 */

int print_rev(char *buffer, unsigned int *len, va_list *s)
{
	char *str = va_arg(*s, char *);
	int length = _strlen(str) - 1;
	int count = 0;

	while (length >= 0)
	{
		buffer[*len] = str[length];
		*len += 1;
		length--;
		count++;
	}
	return (count);
}

/**
 * _strlen - returns the length of a string
 *
 * @s: the string whose length to return
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * rot13 - encodes a string using rot13
 * @buffer: string buffer storage
 * @len: length buffer
 * @s: the string to encode
 *
 * Return: the new string
 */

int rot13(char *buffer, unsigned int *len, va_list *s)
{
	int count, j;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char n[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	char *str = va_arg(*s, char *);

	for (count = 0; str[count] != '\0'; count++)
	{
		for (j = 0; j < 56; j++)
		{
			if (str[count] == a[j])
			{
				buffer[*len] = n[j];
				*len += 1;
				break;
			}
		}
	}

	return (count);
}

#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct func_calls - stores formart specifier and its function
 * @specifier: type to print
 * @func: pointer to a function for checking
 * Description: stores functions easy way to print the right data
 */
struct func_calls
{
	char *specifier;

	int (*func)(char *buffer, unsigned int *len, va_list *ap);
};

/**
 * func_calls - Typedef for struct for func_calls
 */
typedef struct func_calls func_calls;

int _putchar(char c);
int print_s_count(char *buffer, unsigned int *len, char *str);
void check_write_buffer(char *buffer, unsigned int *len);
int convert_to_base(char *buffer, unsigned int *len,
	unsigned int num, unsigned int base,
	unsigned int case_print);
void check_write_buffer(char *buffer, unsigned int *len);
int print_x(char *buffer, unsigned int *len, va_list *x);
int print_X(char *buffer, unsigned int *len, va_list *X);
int print_o(char *buffer, unsigned int *len, va_list *o);
int print_p(char *buffer, unsigned int *len, va_list *p);
int print_b(char *buffer, unsigned int *len, va_list *deci);
int print_d(char *buffer, unsigned int *len, va_list *deci);
int print_u(char *buffer, unsigned int *len, va_list *deci);
int _printf_function_switch(char *buffer, unsigned int *len,
	va_list *s,
	const char specifier);
int print_c(char *buffer, unsigned int *len, va_list *c);
char *create_buffer();
int print_s(char *buffer, unsigned int *len, va_list *s);
int _printf(const char *format, ...);
int print_rev(char *buffer, unsigned int *len, va_list *s);
int _strlen(char *s);
int rot13(char *buffer, unsigned int *len, va_list *s);
int print_perc(char *buffer, unsigned int *len, va_list *c);
#endif


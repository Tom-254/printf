#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct specifier - contains specifiers for printf
 *
 * @width: width of field to print
 * @precision: precision of field to print
 * @length: modifier type length. h/l flags. 0 defualt, +1 per l, -1 per h
 * @widthflag: tels whether width is set
 * @precisionflag: tells whether precision is set
 * @let: left justify, '-'. 0 for right, 1 for left
 * @sign: force sign, '+'. 0 for no, 1 for yes
 * @space: space pad left side of positive numbers if leading 0s. 0 no 1 yes
 * @zero: zero pad numbers up to width. 0 for nom 1 for yes.
 * @zerox: add leading 0, 0x, or 0X to o, x or X specifiers. 0 no 1 yes
 * @specifier: the data type to print, c, s, d, x, etc.
 *
 */

typedef struct specifier
{
	unsigned int width;
	unsigned int precision;
	int length;
	char widthflag;
	char precisionflag;
	char left;
	char sign;
	char space;
	char zero;
	char zerox;
	char specifier;
} specifier;

/* from printf.c */
int _printf(char *format, ...);

#endif

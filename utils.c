#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hex_code - Append ascci in hexadecimal code to buffer
 * @bffr: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hex_code(char ascii_code, char bffr[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	bffr[i++] = '\\';
	bffr[i++] = 'x';

	bffr[i++] = map_to[ascii_code / 16];
	bffr[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_sz_num - Casts a number to the specified size
 * @number: Number to be casted.
 * @sz: Number indicating the type to be casted.
 *
 * Return: Casted value of number
 */
long int convert_sz_num(long int number, int sz)
{
	if (sz == S_LONG)
		return (number);
	else if (sz == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_sz_unsgnd - Casts a number to the specified size
 * @number: Number to be casted
 * @sz: Number indicating the type to be casted
 *
 * Return: Casted value of number
 */
long int convert_sz_unsgnd(unsigned long int number, int sz)
{
	if (sz == S_LONG)
		return (number);
	else if (sz == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}


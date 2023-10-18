#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (wrte(1, &bffr[i], BUFF_SZ - i - 1));*/
	return (wrte_pointer(bffr, ind, length,
		width, flgs, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list tpes, char bffr[],
	int flgs, int width, int precision, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(tpes, char *);

	UNUSED(flgs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(sz);

	if (str == NULL)
		return (wrte(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			bffr[i + offset] = str[i];
		else
			offset += append_hex_code(str[i], buffer, i + offset);

		i++;
	}

	bffr[i + offset] = '\0';

	return (wrte(1, bffr, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list tpes, char bffr[],
	int flgs, int width, int precision, int sz)
{
	char *str;
	int i, tally = 0;

	UNUSED(bffr);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(sz);

	str = va_arg(tpes, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		wrte(1, &z, 1);
		tally++;
	}
	return (tally);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int tally = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(tpes, char *);
	UNUSED(bffr);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				wrte(1, &x, 1);
				tally++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			wrte(1, &x, 1);
			tally++;
		}
	}
	return (tally);
}


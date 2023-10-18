#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @tpes: Lists of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	char extr_c = 0, padd = ' ';
	int ind = BUFF_SZ - 2, lenth = 2, padd_strt = 1; /* lenth=2, for '0x' */
	unsigned long number_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(tpes, void *);

	UNUSED(width);
	UNUSED(sz);

	if (addrs == NULL)
		return (wrte(1, "(nil)", 5));

	bffr[BUFF_SZ - 1] = '\0';
	UNUSED(precision);

	number_addrs = (unsigned long)addrs;

	while (number_addrs > 0)
	{
		bffr[ind--] = map_to[number_addrs % 16];
		number_addrs /= 16;
		lenth++;
	}

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padd = '0';
	if (flgs & F_PLUS)
		extr_c = '+', lenth++;
	else if (flgs & F_SPACE)
		extr_c = ' ', lenth++;

	ind++;

	/*return (wrte(1, &bffr[i], BUFF_SZ - i - 1));*/
	return (wrte_pointer(bffr, ind, lenth,
		width, flgs, padd, extr_c, padd_strt));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @tpes: Lists of arguments
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
			offset += append_hex_code(str[i], bffr, i + offset);

		i++;
	}

	bffr[i + offset] = '\0';

	return (wrte(1, bffr, i + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @tpes: Lists of arguments
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
 * @tpes: Lists of arguments
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


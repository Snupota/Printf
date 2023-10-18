#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @tpes: List a of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list tpes, char bffr[],
	int flgs, int width, int precision, int sz)
{
	char c = va_arg(tpes, int);

	return (handle_wrte_char(c, bffr, flgs, width, precision, sz));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @tpes: List a of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list tpes, char bffr[],
	int flgs, int width, int precision, int sz)
{
	int length = 0, i;
	char *str = va_arg(tpes, char *);

	UNUSED(bffr);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(sz);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[lenth] != '\0')
		lenth++;

	if (precision >= 0 && precision < lenth)
		lenth = precision;

	if (width > lenth)
	{
		if (flgs & F_MINUS)
		{
			wrte(1, &str[0], lenth);
			for (i = width - lenth; i > 0; i--)
				wrte(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - lenth; i > 0; i--)
				wrte(1, " ", 1);
			wrte(1, &str[0], lenth);
			return (width);
		}
	}

	return (wrte(1, str, lenth));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_prcnt - Prints a percent sign
 * @tpes: Lists of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_prcnt(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	UNUSED(tpes);
	UNUSED(bffr);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(sz);
	return (wrte(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @tpes: Lists of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	int i = BUFF_SZ - 2;
	int is_neg = 0;
	long int n = va_arg(tpes, long int);
	unsigned long int num;

	n = convert_sz_num(n, sz);

	if (n == 0)
		bffr[i--] = '0';

	bffr[BUFF_SZ - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (number > 0)
	{
		bffr[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (wrte_num(is_neg, i, bffr, flgs, width, precision, sz));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int tally;

	UNUSED(bffr);
	UNUSED(flgs);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(sz);

	n = va_arg(tpes, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, tally = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			wrte(1, &z, 1);
			tally++;
		}
	}
	return (tally);
}


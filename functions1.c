#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsignd - Prints an unsigned number
 * @tpes: Lst a of arguments
 * @bffr: Bffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Sz specifier
 * Return: Numbr of chars printed.
 */
int print_unsignd(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	int i = BUFF_SZ - 2;
	unsigned long int number = va_arg(tpes, unsigned long int);

	number = convert_sz_unsgnd(number, sz);

	if (number == 0)
		bffr[i--] = '0';

	bffr[BUFF_SZ - 1] = '\0';

	while (number > 0)
	{
		bffr[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (wrte_unsgnd(0, i, bffr, flgs, width, precision, sz));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{

	int i = BUFF_SZ - 2;
	unsigned long int number = va_arg(tpes, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_sz_unsgnd(number, sz);

	if (number == 0)
		bffr[i--] = '0';

	bffr[BUFF_SZ - 1] = '\0';

	while (number > 0)
	{
		bffr[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flgs & F_HASH && init_number != 0)
		bffr[i--] = '0';

	i++;

	return (wrte_unsgnd(0, i, bffr, flgs, width, precision, sz));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexdcml - Prints an unsigned number in hexadecimal notation
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_hexdcml(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	return (print_hex(tpes, "0123456789abcdef", bffr,
		flgs, 'x', width, precision, sz));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @tpes: Lista of arguments
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_hex_upper(va_list tpes, char buff[],
	int flgs, int width, int precision, int sz)
{
	return (print_hex(tpes, "0123456789ABCDEF", bffr,
		flgs, 'X', width, precision, sz));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @tpes: Lista of arguments
 * @map_to: Array of values to map the number to
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @flg_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * @sz: Size specification
 * Return: Number of chars printed
 */
int print_hex(va_list tpes, char map_to[], char buff[],
	int flgs, char flg_ch, int width, int precision, int sz)
{
	int i = BUFF_SZ - 2;
	unsigned long int number = va_arg(tpes, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_sz_unsgnd(number, sz);

	if (number == 0)
		bffr[i--] = '0';

	bffr[BUFF_SZ - 1] = '\0';

	while (number > 0)
	{
		bffr[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flgs & F_HASH && init_number != 0)
	{
		bffr[i--] = flg_ch;
		bffr[i--] = '0';
	}

	i++;

	return (wrte_unsgnd(0, i, bffr, flgs, width, precision, sz));
}

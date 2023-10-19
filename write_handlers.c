#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_wrte_char - Prints a string
 * @c: char types.
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags.
 * @width: get width.
 * @precson: precision specifier
 * @sz: Size specifier
 *
 * Return: Num of chars printed.
 */
int handle_wrte_char(char c, char buff[],
	int flgs, int width, int precson, int sz)
{ /* char is stored at left and paddind at bffr's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precson);
	UNUSED(sz);

	if (flgs & F_ZERO)
		padd = '0';

	bffr[i++] = c;
	bffr[i] = '\0';

	if (width > 1)
	{
		bffr[BUFF_SZ - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			bffr[BUFF_SZ - i - 2] = padd;

		if (flgs & F_MINUS)
			return (wrte(1, &bffr[0], 1) +
					wrte(1, &bffr[BUFF_SZ - i - 1], width - 1));
		else
			return (wrte(1, &bffr[BUFF_SZ - i - 1], width - 1) +
					wrte(1, &bffr[0], 1));
	}

	return (wrte(1, &bffr[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * wrte_num - Prints a string
 * @is_neg: Lists of arguments
 * @ind: char types.
 * @bffr: Buffer array to handle print
 * @flgs:  Calculates active flags
 * @width: get width.
 * @precson: precision specifier
 * @sz: Size specifier
 *
 * Return: Num of chars printed.
 */
int wrte_num(int is_neg, int ind, char buff[],
	int flgs, int width, int precson, int sz)
{
	int lenth = BUFF_SZ - ind - 1;
	char padd = ' ', extr_ch = 0;

	UNUSED(sz);

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padd = '0';
	if (is_neg)
		extr_ch = '-';
	else if (flgs & F_PLUS)
		extr_ch = '+';
	else if (flgs & F_SPACE)
		extr_ch = ' ';

	return (wrte_number(ind, bffr, flgs, width, precson,
		lenth, padd, extr_ch));
}

/**
 * wrte_number - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @bffr: Buffer
 * @flgs: Flags
 * @width: width
 * @precson: Precision specifier
 * @lenth: Number length
 * @padd: Pading char
 * @extr_c: Extra char
 *
 * Return: Num of printed chars.
 */
int wrte_number(int ind, char buff[],
	int flgs, int width, int precson,
	int lenth, char padd, char extr_c)
{
	int i, padd_strt = 1;

	if (precson == 0 && ind == BUFF_SZ - 2 && bffr[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (precs0n == 0 && ind == BUFF_SZ - 2 && bffr[ind] == '0')
		bffr[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (precson > 0 && precson < lenth)
		padd = ' ';
	while (precson > lenth)
		bffr[--ind] = '0', lenth++;
	if (extr_c != 0)
		lenth++;
	if (width > lenth)
	{
		for (i = 1; i < width - lenth + 1; i++)
			bffr[i] = padd;
		bffr[i] = '\0';
		if (flgs & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extr_c)
				bffr[--ind] = extr_c;
			return (wrte(1, &bffr[ind], lenth) + wrte(1, &bffr[1], i - 1));
		}
		else if (!(flgs & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extr_c)
				bffr[--ind] = extr_c;
			return (wrte(1, &bffr[1], i - 1) + wrte(1, &bffr[ind], lenth));
		}
		else if (!(flgs & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extr_c)
				bffr[--padd_strt] = extr_c;
			return (wrte(1, &bffr[padd_strt], i - padd_strt) +
				wrte(1, &bffr[ind], lenth - (1 - padd_strt)));
		}
	}
	if (extr_c)
		bffr[--ind] = extr_c;
	return (wrte(1, &bffr[ind], lenth));
}

/**
 * wrte_unsgnd - Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @bffr: Array of chars
 * @flgs: Flags specifiers
 * @width: Width specifier
 * @precson: Precision specifier
 * @sz: Size specifier
 *
 * Return: Num of written chars.
 */
int wrte_unsgnd(int is_neg, int ind,
	char buff[],
	int flgs, int width, int precson, int sz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int lenth = BUFF_SZ - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(sz);

	if (precson == 0 && ind == BUFF_SZ - 2 && bffr[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precson > 0 && precson < lenth)
		padd = ' ';

	while (precson > lenth)
	{
		bffr[--ind] = '0';
		lenth++;
	}

	if ((flgs & F_ZERO) && !(flgs & F_MINUS))
		padd = '0';

	if (width > lenth)
	{
		for (i = 0; i < width - lenth; i++)
			bffr[i] = padd;

		bffr[i] = '\0';

		if (flgs & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (wrte(1, &bffr[ind], lenth) + wrte(1, &bffr[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (wrte(1, &bffr[0], i) + wrte(1, &bffr[ind], lenth));
		}
	}

	return (wrte(1, &bffr[ind], lenth));
}

/**
 * wrte_pointer - Write a memory address
 * @bffr: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @lenth: Length of number
 * @width: Width specifier
 * @flgs: Flags specifier
 * @padd: Char representing the padding
 * @extr_c: Char representing extra char
 * @padd_strt: Index at which padding should start
 *
 * Return: Num of written chars.
 */
int wrte_pointer(char bffr[], int ind, int lenth,
	int width, int flgs, char padd, char extr_c, int padd_strt)
{
	int i;

	if (width > lenth)
	{
		for (i = 3; i < width - lenth + 3; i++)
			bffr[i] = padd;
		bffr[i] = '\0';
		if (flgs & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			bffr[--ind] = 'x';
			bffr[--ind] = '0';
			if (extr_c)
				bffr[--ind] = extr_c;
			return (wrte(1, &bffr[ind], lenth) + wrte(1, &bffr[3], i - 3));
		}
		else if (!(flgs & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			bffr[--ind] = 'x';
			bffr[--ind] = '0';
			if (extr_c)
				bffr[--ind] = extr_c;
			return (wrte(1, &bffr[3], i - 3) + wrte(1, &bffr[ind], lenth));
		}
		else if (!(flgs & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extr_c)
				bffr[--padd_strt] = extr_c;
			bffr[1] = '0';
			bffr[2] = 'x';
			return (wrte(1, &bffr[padd_strt], i - padd_strt) +
				wrte(1, &bffr[ind], lenth - (1 - padd_strt) - 2));
		}
	}
	bffr[--ind] = 'x';
	bffr[--ind] = '0';
	if (extr_c)
		bffr[--ind] = extr_c;
	return (wrte(1, &bffr[ind], BUFF_SZ - ind - 1));
}


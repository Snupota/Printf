#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @formt: Formatted string in which to print the arguments.
 * @lst: List of arguments to be printed.
 * @ind: ind.
 * @bffr: Buffer array to handle print.
 * @flgs: Calculates active flags
 * @width: get width.
 * @precson: Precision specification
 * @sz: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *formt, int *ind, va_list lst, char buff[],
	int flgs, int width, int precson, int sz)
{
	int i, unknow_len = 0, prntd_chars = -1;
	formt_t formt_tpes[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_prcnt},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexdcml},
		{'X', print_hex_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; formt_tpes[i].formt != '\0'; i++)
		if (formt[*ind] == formt_tpes[i].formt)
			return (formt_tpes[i].fn(lst, bffr, flgs, width, precson, sz));

	if (formt_tpes[i].formt == '\0')
	{
		if (formt[*ind] == '\0')
			return (-1);
		unknow_len += wrte(1, "%%", 1);
		if (formt[*ind - 1] == ' ')
			unknow_len += wrte(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (formt[*ind] != ' ' && formt[*ind] != '%')
				--(*ind);
			if (formt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += wrte(1, &formt[*ind], 1);
		return (unknow_len);
	}
	return (prntd_chars);
}


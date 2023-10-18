#include "main.h"

void print_buf(char buff[], int *buffer_ind);

/**
 * _printf - Printf fun
 * @formt: format.
 * Return: Printed chars.
 */
int _printf(const char *formt, ...)
{
	int i, printed = 0, prntd_chars = 0;
	int flgs, width, precision, sz, buffer_ind = 0;
	va_list lst;
	char buff[BUFF_SIZE];

	if (formt == NULL)
		return (-1);

	va_start(lst, formt);

	for (i = 0; formt && formt[i] != '\0'; i++)
	{
		if (formt[i] != '%')
		{
			bffr[buffer_ind++] = formt[i];
			if (buffer_ind == BUFF_SZ)
				print_buf(bffr, &buffer_ind);
			/* wrte(1, &formt[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buf(bffr, &buffer_ind);
			flgs = get_flgs(formt, &i);
			width = get_width(formt, &i, lst);
			precision = get_precision(formt, &i, lst);
			sz = get_sz(formt, &i);
			++i;
			printed = handle_print(formt, &i, lst, bffr,
				flgs, width, precision, sz);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buf(bffr, &buffer_ind);

	va_end(lst);

	return (printed_chars);
}

/**
 * print_buf - Prints the contents of the buffer if it exist
 * @bffr: Array of chars
 * @buffer_ind: Index at which to add next char, represents the length.
 */
void print_buf(char buff[], int *buffer_ind)
{
	if (*buffer_ind > 0)
		wrte(1, &bffr[0], *buffer_ind);

	*buffer_ind = 0;
}

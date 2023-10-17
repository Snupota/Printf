#include "main.h"

void print_buf(char buff[], int *buffer_ind);

/**
 * _printf - Printf fun
 * @format: format.
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
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

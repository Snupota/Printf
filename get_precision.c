#include "main.h"

/**
 * get_precson - Calculates the precision for printing
 * @formt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @lst: list of arguments.
 *
 * Return: Precson.
 */
int get_precson(const char *formt, int *i, va_list lst)
{
	int curr_i = *i + 1;
	int precson = -1;

	if (formt[curr_i] != '.')
		return (precson);

	precson = 0;

	for (curr_i += 1; formt[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(formt[curr_i]))
		{
			precson *= 10;
			precson += formt[curr_i] - '0';
		}
		else if (formt[curr_i] == '*')
		{
			curr_i++;
			precson = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precson);
}


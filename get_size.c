#include "main.h"

/**
 * get_sz - Calculates the size to cast the argument
 * @formt: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precson.
 */
int get_sz(const char *formt, int *i)
{
	int curr_i = *i + 1;
	int sz = 0;

	if (formt[curr_i] == 'l')
		sz = S_LONG;
	else if (formt[curr_i] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sz);
}


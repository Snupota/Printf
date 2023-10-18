#include "main.h"

/**
 * get_flgs - Calculates active flags
 * @formt: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flgs:
 */
int get_flgs(const char *formt, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flgs = 0;
	const char FLGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; formt[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLGS_CH[j] != '\0'; j++)
			if (formt[curr_i] == FLGS_CH[j])
			{
				flgs |= FLGS_ARR[j];
				break;
			}

		if (FLGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flgs);
}


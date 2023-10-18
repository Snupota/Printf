#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SZ 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct formt - Struct op
 *
 * @formt: The format.
 * @fn: The function associated.
 */
struct formt
{
	char formt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct formt formt_t - Struct op
 *
 * @formt: The format.
 * @fm_t: The function associated.
 */
typedef struct formt formt_t;

int _printf(const char *formt, ...);
int handle_print(const char *formt, int *i,
va_list lst, char buff[], int flgs, int width, int precson, int sz);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_string(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_prcnt(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);

/* Functions to print numbers */
int print_int(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_binary(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_unsigned(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_octal(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_hexdcml(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);
int print_hex_upper(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);

int print_hex(va_list tpes, char map_to[],
char buff[], int flgs, char flag_ch, int width, int precson, int sz);

/* Function to print non printable characters */
int print_non_printable(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);

/* Funcion to print memory address */
int print_pointer(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);

/* Funciotns to handle other specifiers */
int get_flgs(const char *formt, int *i);
int get_width(const char *formt, int *i, va_list lst);
int get_precson(const char *formt, int *i, va_list lst);
int get_sz(const char *formt, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);

/*Function to print a string in rot 13*/
int print_rot13string(va_list tpes, char buff[],
	int flgs, int width, int precson, int sz);

/* width handler */
int handle_write_char(char c, char buff[],
	int flgs, int width, int precson, int sz);
int wrte_num(int is_positive, int ind, char buff[],
	int flgs, int width, int precson, int sz);
int wrte_number(int ind, char bff[], int flgs, int width, int precson,
	int lenth, char padd, char extr_c);
int write_pointer(char buff[], int ind, int lenth,
	int width, int flgs, char padd, char extr_c, int padd_strt);

int write_unsgnd(int is_neg, int ind,
char buff[],
	int flgs, int width, int precson, int sz);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_sz_num(long int number, int sz);
long int convert_sz_unsgnd(unsigned long int number, int sz);

#endif /* MAIN_H */


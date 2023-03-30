#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: char
 * Return: 1 if c is printa, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}


/**
 * append_hexa code - append to buffer hexadecimal code
 * @buffer: buffer array
 * @i: index to start append
 * @ascii_code: ASCII CODE
 * Return: 3 (SUCCESS)
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* Hexa format code always 2 digit long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies if a char is a digit
 * @c: char
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - cast a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - cast a number to be specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

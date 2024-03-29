#include "main.h"

	/*****WRITE HANDLE*****/
/**
 * handle_write_char - prints a string
 * @c: char types
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size
 * Return: number of char
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	/* char is stored at left and padding at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1, i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
			write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1)
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}


	/*****WRITE NUMBER*****/
/**
 * write_number - prints a string
 * @is_negative: list arguments
 * @ind: char types
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size
 * Return: number of char printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}

/**
 * write_num - write number using buffer
 * @ind: index at which the number starts on buffer
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision specifier
 * @length: number length
 * @padd: padding char
 * @extra_c: extra char
 * Return: number of printed char
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 &&
			buffer[ind] == '0' && width == 0)
		return (0); /*printf(".0d", 0) no char is printed*/
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	/*width is displayed with padding' '*/
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
			/*Asign extra char to left of buffer*/
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1,
						&buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
			/*etra char to left of buff*/
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, buffer[padd_start], i - padd_start) +
			write(1, buffer[ind], length - (1 - padd_start) - 2));
		}

	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

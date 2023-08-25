#include "monty.h"
#include <stdlib.h>

char *chari_intget (int num);
unsigned int val_abs(int);
int bufferlength(unsigned int num, unsigned int base);
void buffer_fillbase(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * chari_intget - get a char pointer to new str with int
 * @num: to be converted to a string
 *
 * Return: new string created. if malloc fails NULL
 */
char *chari_intget(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = val_abs(num);
	length = bufferlength(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* - sign */
	ret = malloc(length + 1); /* new string creator */
	if (!ret)
		return (NULL);

	buffer_fillbase(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * val_abs - absolute value of an integer to ghet
 * @i: integer to find the absolute value of
 *
 * Return: absolute value of the integer
 */
unsigned int val_abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * bufferlength - func to get the length of the buffer
 * @num: number to get length
 * @base: base of number representation used by buffer
 *
 * Return: length of the buffer from the integer
 */
int bufferlength(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * buffer_fillbase - buffer to fill with right numbers up to base 36
 * @num: to be converted to a string to a given base
 * @base: number used in conversion base
 * @buff: bufer to be fillled with the converted value
 * @buff_size: buffer size in bytes
 *
 * Return: VOID.
 */
void buffer_fillbase(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

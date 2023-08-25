#include <stdlib.h>

char **strtow(char *str, char *delims);
int monty_delim(char ch, char *delims);
int montywordlen(char *str, char *delims);
int montywordcount(char *str, char *delims);
char *montynextword(char *str, char *delims);

/**
 * strtow - func separates strings from words
 *
 * @str: string var to seperate into words
 * @delims: delimeters
 *
 * Return: pointer from 2D array
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = montywordcount(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = montywordlen(str, delims);
		if (monty_delim(*str, delims))
		{
			str = montynextword(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = montynextword(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * monty_delim - func to checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: delimeters
 *
 * Return: 1 success 0 on (failure)
 */

int monty_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * montywordlen - func to gets the word lrn of cur word in string
 *
 * @str: var to seperate into words
 * @delims: delimiters to use to delimit words in code
 *
 * Return: current word lenth
 */

int montywordlen(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (monty_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && monty_delim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * montywordcount - func to gets the word count of a string
 *
 * @str: var to seperate into words
 * @delims: delimiters to use to delimit words
 *
 * Return: count of the string
 */

int montywordcount(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (monty_delim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * montynextword - finds the next word of a string
 *
 * @str: var to seperate into words
 * @delims: delimiters to use to delimit words
 *
 * Return: char in word pointer
 */

char *montynextword(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (monty_delim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

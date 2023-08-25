#include "monty.h"

/**
 * error_optokens - Sets last element of op_toks to be an error code.
 * @err_code: Integer to store as a string in op_toks.
 */
void error_optokens(int err_code)
{
	int lentok = 0, i = 0;
	char *string_exit = NULL;
	char **new_tokens = NULL;

	lentok = montytokenlen();
	new_tokens = malloc(sizeof(char *) * (lentok + 2));
	if (!op_toks)
	{
		monty_mallocerror();
		return;
	}
	while (i < lentok)
	{
		new_tokens[i] = op_toks[i];
		i++;
	}
	string_exit = chari_intget(err_code);
	if (!string_exit)
	{
		free(new_tokens);
		monty_mallocerror();
		return;
	}
	new_tokens[i++] = string_exit;
	new_tokens[i] = NULL;
	free(op_toks);
	op_toks = new_tokens;
}

#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - montry interpreter main entry point
 *
 * @argc: number of arguments passed to the program
 * @argv: arrays pointers of arguments from char pointers
 *
 * Return: (EXIT_SUCCESS) true (EXIT_FAILURE) on failure
 */
int main(int argc, char **argv)
{
	FILE *monty_fd = NULL;
	int quit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (monty_errorprinter());
	monty_fd = fopen(argv[1], "r");
	if (monty_fd == NULL)
		return (fileopen_error(argv[1]));
	quit_code = exe_monty(monty_fd);
	fclose(monty_fd);
	return (quit_code);
}

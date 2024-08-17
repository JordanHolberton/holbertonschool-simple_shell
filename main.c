#include "shell.h"

/**
 * main - principal entry of the shell.
 * This function ignore the arguments with (void)
 * It call shell_loop()
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: Always `EXIT_SUCCESS`.
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	shell_loop();

	return (EXIT_SUCCESS);
}

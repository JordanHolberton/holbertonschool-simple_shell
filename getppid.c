#include "supershell.h"

/**
 * Function to print the process IDs
 */

void print_process_info(const char* process_type)
{
	printf("%s: Current ID: %d, parent ID: %d\n", process_type, getpid(),
			getppid());
}

/**
 * Function to handle the child process
 */

void child_process()
{
	sleep(1);
	print_process_info("Child");
}

/**
 * Function to handle the parent process
 */

void parent_process(int child_id)
{
	print_process_info("Parent");
	int res = wait(NULL);
	if (res == -1)
	{
		printf("No child to wait for\n");
	}
	else
	{
		printf("Child %d finished the execution\n", res);
	}
}

int main (int argc, char* argv[])
{
	int id = fork();
	if (id == 0)
	{
		child_process();
	}
	else
	{
		parent_process(id);
	}

	return 0;
}

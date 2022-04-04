#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv)
{
	int id;

	if (argc == 2)
	{
		id = atoi(argv[1]);
		printf("Ejecutando cliente... %d \n", id);
		kill(id, SIGKILL);
	}
	return(0);
}

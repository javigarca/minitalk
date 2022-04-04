#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
//int main(int argc, char**argv)
{
	int id;
	int num;

	num = 0;
	id = getpid();
	printf("ID : %d \n", id);
	while (1)
	{
		printf("%d \n", num++);
		sleep(1);
	}
	return(0);
}

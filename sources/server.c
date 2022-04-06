#include "../include/minitalk.h"

int main(void)
//int main(int argc, char**argv)
{
	int id;
	int num;

	num = 0;
	id = getpid();
	ft_putstr_fd("ID :", 1);
	ft_putnbr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		ft_putnbr_fd(num++,1);
		ft_putstr_fd("\n", 1);
		sleep(1);
	}
	return(0);
}

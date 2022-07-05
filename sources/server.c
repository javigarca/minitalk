#include "../include/minitalk.h"

void ft_received_sig(int sig)
{
	static int bit = 0;
	static char messrec = 0;

	if (sig == SIGUSR2)
		messrec |= (0x01 << bit);
	bit++;
	if (bit == 7)
	{
		write(1, &messrec, 1);
		messrec = 0;
		bit = -1;
	}
}

int main(int argc, char **argv)
{
	int id;

	if (argc != 1)
	{
		ft_putstr_fd("El programa server no necesita argumentos.\n", 1);
		ft_putstr_fd(argv[0], 1);
		return (1);
	}
	id = getpid();
	ft_putstr_fd("ID :", 1);
	ft_putnbr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		signal(SIGUSR1, ft_received_sig);
		signal(SIGUSR2, ft_received_sig);	
		pause();
	}
	return(0);
}

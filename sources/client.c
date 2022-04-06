#include "../include/minitalk.h"

void	ft_send_message(char *mess, int pid)
{
	int i;

	while (*mess)
	{
		i = 0;
		while (i++ < 9)
		{
			if ((*mess & 0x01))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			*mess >>= 1;
		}
	}
	write(1, "Mensaje enviado.\n", 17);
}

int main(int argc, char**argv)
{
	int		id;
	
	if (argc == 3)
	{
		id = ft_atoi(argv[1]);
		if (id)
		{
			ft_putstr_fd("Ejecutando cliente... ", 1);
			ft_putnbr_fd(id, 1);
			ft_putstr_fd("\n", 1);
			ft_send_message(argv[2], id);
	//		kill(id, SIGKILL);
		}
		else
			write(1, "Escriba el número de proceso del servidor correctamente.\n", 58);
	}
	else
		write(1, "Escriba client, el número de proceso del servidor y la cadena a pasar.\n", 72);
	return(0);
}

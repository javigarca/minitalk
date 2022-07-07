/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javigarc <javigarc@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:53:52 by javigarc          #+#    #+#             */
/*   Updated: 2022/03/10 11:53:54 by javigarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	ft_send_message(char *mess, int pid)
{
	int	i;

	while (*mess)
	{
		i = 0;
		while (i < 8)
		{
			if ((*mess >> i) & 0x01)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			usleep(200);
		}
		mess++;
	}
	write(1, "\nFin del cliente.\n", 18);
}

void	ft_received_server(int sig)
{
	if (sig == SIGUSR2)
		write(1, "✅", 4);
}

int	main(int argc, char**argv)
{
	int	id;

	if (argc == 3)
	{
		id = ft_atoi(argv[1]);
		if (id)
		{
			ft_putstr_fd("Ejecutando cliente... ", 1);
			ft_putnbr_fd(id, 1);
			ft_putstr_fd("\n", 1);
			signal(SIGUSR2, ft_received_server);
			ft_send_message(argv[2], id);
		}
		else
			write(1, "Escriba el pid de server correctamente.\n", 41);
	}
	else
		write(1, "Escriba ./client, el pid de server y el mensaje.\n", 49);
	return (0);
}

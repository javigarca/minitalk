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

#include "../include/minitalk.h"

void	ft_send_empty(int pid)
{
	int	i;

	i = 8;
	while (--i)
	{
		kill(pid, SIGUSR1);
		usleep(800);
	}
}

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
			usleep(800);
		}
		mess++;
	}
	ft_send_empty(pid);
	write(1, "\nFin del cliente.\n", 18);
}

void	ft_received_server(int sig, siginfo_t *info, void *ucontext)
{
	int static	okeys = 0;

	(void)info;
	(void)ucontext;
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("\rBytes recibidos correctamente: ", 1);
		ft_putnbr_fd(++okeys, 1);
	}
	usleep(100);
}

int	main(int argc, char**argv)
{
	int					id;
	struct sigaction	ssg;

	ssg.sa_flags = SA_SIGINFO;
	ssg.sa_sigaction = ft_received_server;
	sigaction(SIGUSR2, &ssg, NULL);
	sigaction(SIGUSR1, &ssg, NULL);
	if (argc == 3)
	{
		id = ft_atoi(argv[1]);
		if (id)
		{
			ft_putstr_fd("Ejecutando cliente... ", 1);
			ft_putnbr_fd(id, 1);
			ft_putstr_fd("\nBytes totales del mensaje: ", 1);
			ft_putnbr_fd(ft_strlen(argv[2]), 1);
			ft_putstr_fd("\n", 1);
			ft_send_message(argv[2], id);
		}
		else
			write(1, "Escriba el pid de server correctamente.\n", 41);
	}
	else
		write(1, "Escriba ./client, el pid de server y el mensaje.\n", 49);
	return (0);
}

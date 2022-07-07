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

void	ft_received_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int		bit;
	static char		messrec;
	static pid_t	client_pid;

	(void)ucontext;
	if (client_pid != info->si_pid)
	{
		messrec = 0;
		bit = 0;
	}
	if (sig == SIGUSR2)
		messrec |= (0x01 << bit);
	if (++bit == 8)
	{
		write(1, &messrec, 1);
		messrec = 0;
		bit = 0;
	}
	client_pid = info->si_pid;
	kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	ssg;

	if (argc != 1)
	{
		ft_putstr_fd("El programa server no necesita argumentos. USO: ", 1);
		ft_putstr_fd(argv[0], 1);
		return (1);
	}
	ssg.sa_flags = SA_SIGINFO;
	ssg.sa_sigaction = ft_received_sig;
	ft_putstr_fd("Server PID :", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &ssg, NULL);
	sigaction(SIGUSR2, &ssg, NULL);
	while (42)
	{
		pause();
	}
	return (0);
}
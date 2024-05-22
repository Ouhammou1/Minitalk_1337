/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:50:24 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/20 22:50:26 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_glb = 0;

int	ft_power(int a, int b)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while (i < b)
	{
		s = s * a;
		i++;
	}
	return (s);
}

void	handle_signal(int sig, struct __siginfo *info, void *nul)
{
	static int	s;
	static int	temp_pid;

	(void)*nul;
	if (info->si_pid != temp_pid)
	{
		g_glb = 0;
		s = 0;
		temp_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		g_glb++;
	if (sig == SIGUSR2)
	{
		s += ft_power(2, g_glb);
		g_glb++;
	}
	if (g_glb == 8)
	{
		write(1, &s, 1);
		g_glb = 0;
		s = 0;
	}
}

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	sa;

	(void)ac;
	(void)av;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

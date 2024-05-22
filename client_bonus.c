/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:49:49 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/20 22:49:52 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(int octet, int pid)
{
	int		i;
	char	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		bit = (octet >> i & 1) + 48;
		if (bit == '0')
			kill(pid, SIGUSR1);
		if (bit == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(900);
	}
}

void	send_string(char *str, int pid)
{
	int	i;
	int	len;

	len = ft_strlen(str) + 1;
	i = 0;
	while (i < len)
	{
		send_bits(str[i], pid);
		i++;
	}
}

void	signal_handler(int sig)
{
	(void)sig;
	write(1, "\033[1;32mmessage received successfully\033[0m\n", 37);
	return ;
}

int	main(int ac, char *av[])
{
	int	pid;

	signal(SIGUSR1, signal_handler);
	if (ac != 3)
		write(1, "Error\n", 6);
	else
	{
		pid = ft_atoi(av[1]);
		send_string(av[2], pid);
	}
	return (0);
}

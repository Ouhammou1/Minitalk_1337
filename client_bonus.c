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

char	*conver_binary(int n)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(9 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 7;
	while (i >= 0)
	{
		ptr[i] = (n & 1) + '0';
		n = n >> 1;
		i--;
	}
	ptr[8] = '\0';
	return (ptr);
}

void	send_string(char *str, int pid)
{
	char	*ptr;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(str) + 1;
	i = 0;
	while (i < len)
	{
		j = 7;
		ptr = conver_binary(str[i]);
		while (j >= 0)
		{
			if (ptr[j] == '0')
				kill(pid, SIGUSR1);
			if (ptr[j] == '1')
				kill(pid, SIGUSR2);
			j--;
			usleep(500);
		}
		i++;
		free(ptr);
	}
}

void	signal_handler(int sig)
{
	(void)sig;
	write(1, "message received successfully\n", 30);
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

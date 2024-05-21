/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:49:38 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/20 22:49:40 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*conver_binary(int n)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(9 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (n == 0)
		write(1, "0", 1);
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
	int		j;

	i = 0;
	while (str[i] != '\0')
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

int	main(int ac, char *av[])
{
	int	pid;

	if (ac != 3)
		write(1, "Error\n", 6);
	else
	{
		pid = ft_atoi(av[1]);
		send_string(av[2], pid);
	}
	return (0);
}

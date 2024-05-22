/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:50:00 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/20 22:50:02 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_libft/ft_libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	send_bits(int octet, int pid);
int		ft_power(int a, int b);
void	send_string(char *str, int pid);
void	handle_signal(int sig, struct __siginfo *info, void *nul);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:50:12 by bouhammo          #+#    #+#             */
/*   Updated: 2024/05/20 22:50:14 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "ft_libft/ft_libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_power(int a, int b);
void	handle_signal(int sig, struct __siginfo *info, void *nul);
void	send_bits(int octet, int pid);
void	signal_handler(int sig);

#endif

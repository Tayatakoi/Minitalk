/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:28:06 by samamaev          #+#    #+#             */
/*   Updated: 2025/11/25 23:31:41 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	send_char(int pid, char c);
void	send_string(int pid, char *str);
void    signal_handler(int sig, siginfo_t *info, void *context);

#endif
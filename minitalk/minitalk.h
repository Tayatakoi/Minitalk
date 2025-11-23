/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:55:05 by samamaev          #+#    #+#             */
/*   Updated: 2025/11/19 01:08:10 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	signal_handler(int sig);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	send_char(int pid, char c);
void	send_string(int pid, char *str);

#endif
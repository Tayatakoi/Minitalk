/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 23:13:13 by samamaev          #+#    #+#             */
/*   Updated: 2025/11/26 00:19:20 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!str[0] || str[0] < '0' || str[0] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (INT_MAX - (str[i] - '0')) / 10)
			return (-1);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (result);
}

void	send_char(int pid, char c)
{
	int	bit;
	int	timeout;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		timeout = 0;
		while (!g_ack_received && timeout < 1000)
		{
			usleep(100);
			timeout++;
		}
		if (!g_ack_received)
		{
			write(2, "Error: Server did not respond\n", 31);
			exit(1);
		}
		bit--;
	}
}

void	send_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
	write(1, "Message sent successfully!\n", 27);
}

int	main(int ac, char **av)
{
	int					server_pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(2, "wrong input: ./client [server_pid] [message]\n", 46);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		write(2, "Error: Invalid PID\n", 19);
		return (1);
	}
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	send_string(server_pid, av[2]);
	return (0);
}

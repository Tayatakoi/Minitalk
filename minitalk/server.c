/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:55:09 by samamaev          #+#    #+#             */
/*   Updated: 2025/11/19 01:03:03 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_current_char = 0;

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	signal_handler(int sig)
{
	static int	bit_count = 0;

	g_current_char = g_current_char << 1;
	if (sig == SIGUSR2)
		g_current_char = g_current_char | 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &g_current_char, 1);
		bit_count = 0;
		g_current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

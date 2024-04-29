/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:26:23 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/29 12:10:10 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signum, siginfo_t *info, void *ucontent)
{
	static int	bits;
	static int	c;

	(void)info;
	(void)ucontent;
	if (signum == SIGUSR1)
		c += 1 << (7 - bits);
	bits++;
	if (bits == 8 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		bits = 0;
	}
}

static void	ft_config_server(void)
{
	struct sigaction	sa_server;

	sa_server.sa_sigaction = &ft_handler;
	sa_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_server.sa_mask);
	if (sigaction(SIGUSR1, &sa_server, NULL) < 0)
		ft_handle_error("[SERVER] - Error: SIGUSR1 hasn't been set.");
	else if (sigaction(SIGUSR2, &sa_server, NULL) < 0)
		ft_handle_error("[SERVER] - Error: SIGUSR2 hasn't been set.");
}

int	main(void)
{
	ft_putstr_fd("[SERVER] - PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putendl_fd("\n[SERVER] - Waiting for message...",
		STDOUT_FILENO);
	ft_config_server();
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:26:16 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/29 12:06:20 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putendl_fd("[CLIENT] - Error: wrong format.", STDOUT_FILENO);
		ft_handle_error("[CLIENT] - Example: ./client <PID> <MESSAGE>");
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			ft_handle_error("[CLIENT] - Error: PID is wrong.");
		i++;
	}
	if (*argv[2] == 0)
	{
		ft_handle_error("[CLIENT] - Error: message can not be empty.");
	}
}

static void	ft_send_bits(pid_t sv_pid, char *content)
{
	unsigned char	c;
	int				bits;

	while (*content)
	{
		c = *content;
		bits = 8;
		while (bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(100);
			c <<= 1;
		}
		content++;
	}
}

static void	ft_config_client(void)
{
	struct sigaction	sa_client;

	if (sigaction(SIGUSR1, &sa_client, NULL) < 0)
		ft_handle_error("[CLIENT] - Error: SIGUSR1 hasn't been set.");
	else if (sigaction(SIGUSR2, &sa_client, NULL) < 0)
		ft_handle_error("[CLIENT] - Error: SIGUSR2 hasn't been set.");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	ft_args_check(argc, argv);
	pid = ft_atoi(argv[1]);
	ft_config_client();
	ft_send_bits(pid, argv[2]);
	ft_send_bits(pid, "\n");
	return (0);
}

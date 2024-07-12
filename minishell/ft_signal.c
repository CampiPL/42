/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:34:17 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/08 13:06:14 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	ft_signal(void)
{
	struct sigaction	sa[2];

	ft_memset(sa, 0, sizeof(sa));
	sa[0].sa_handler = ctrl_c;
	sa[1].sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa[0], NULL);
	sigaction(SIGQUIT, &sa[1], NULL);
}

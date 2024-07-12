/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:08:03 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/12 17:05:04 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	reset_std(t_b *mini)
{
	dup2(mini->in, 0);
	dup2(mini->out, 1);
}

void	close_fds(t_b *mini)
{
	// ft_close(mini->fdin);
	// ft_close(mini->fdout);
	ft_close(mini->pipin);
	ft_close(mini->pipout);
}

void	reset_fds(t_b *mini)
{
	// mini->fdin = -1;
	// mini->fdout = -1;
	mini->pipin = -1;
	mini->pipout = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:42:43 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/13 21:41:39 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir(t_b *mini, t_cmd *cmd, int type)
{
	ft_close(mini->fdout);
	if (type == TRUNC)
		mini->fdout = open(cmd->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		mini->fdout = open(cmd->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (mini->fdout == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return ;
	}
	dup2(mini->fdout, 1);
}

void	input(t_b *mini, t_cmd *cmd)
{
	ft_close(mini->fdin);
	mini->fdin = open(cmd->str, O_RDONLY, S_IRWXU);
	if (mini->fdin == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->str, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return ;
	}
	dup2(mini->fdin, 0);
}

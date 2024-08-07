/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 08:08:56 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/12 12:09:49 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean(t_b *tb)//, char **env)
{
	int	i;

	i = -1;
	while (++i < tb->max)
	{
		free(tb->cmd[i].path);
		ft_freelst(tb->cmd[i].cmd);
		free(tb->cmd[i].builtin);
		free(tb->cmd[i].heredoc);
		free(tb->cmd[i].nin);
		free(tb->cmd[i].nout);
	}
	free(tb->cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:12:42 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/19 11:37:24 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(t_b *tb, char *s, int i)
{
	char	*rd;
	char	*hdc;

	hdc = ft_strjoin("/tmp/miniheredoc", ft_itoa(i), 3);
	tb->cmd[i].nin = hdc;
	tb->cmd[i].in = open(hdc, O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		rd = readline("heredoc> ");
		if (!ft_strncmp(rd, s, ft_strlen(s, 0)))
			break ;
		ft_printf(tb->cmd[i].in, "%s\n", rd);
		free(rd);
	}
	free(rd);
}

void	ft_redirin(t_b *tb, char *s, int i)
{
	tb->cmd[i].in = open(av[1], O_RDONLY);
	if (tb->cmd[i].in = -1) // == ?
		ft_printf(2, "no such file or directory: %s\n", s);
}

void	ft_redirout(char *s, t_b *tb, int a, int i)
{
	if (a == 1)
		tb->cmd[i].out = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (a == 2)
		tb->cmd[i].out = open(s, O_WRONLY | O_CREAT | O_APPEND, 0644);
}

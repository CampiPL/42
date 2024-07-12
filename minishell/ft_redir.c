/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:12:42 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/12 12:10:47 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(char *s)
{
	char		*rd;
	char		*hdc;
	static int	nb;
	int			fd;

	hdc = ft_strjoin("/tmp/miniheredoc", ft_itoa(nb++), 3);
	fd = open(hdc, O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		rd = readline("heredoc> ");
		if (!ft_strncmp(rd, s, ft_strlen(s, 0)))
			break ;
		ft_printf(fd, "%s\n", rd);
		free(rd);
	}
	return (free(s), free(rd), fd);
}

int	ft_redirin(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_printf(2, "no such file or directory: %s\n", s);
	return (free(s), fd);
}

int	ft_redirout(char *s, int a)
{
	if (a == 1)
		return (open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	if (a == 2)
		return (open(s, O_WRONLY | O_CREAT | O_APPEND, 0644));
}

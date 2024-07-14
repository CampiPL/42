/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:14:02 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/14 17:03:07 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_cbuiltin(char *s)
{
	if (!ft_strncmp("cd ", s, 3))
		return (1);
	if (!ft_strncmp("echo -n ", s, 8))
		return (1);
	if (!ft_strncmp("echo ", s, 5))
		return (1);
	if (!ft_strncmp("env ", s, 4))
		return (1);
	if (!ft_strncmp("export ", s, 7))
		return (1);
	if (!ft_strncmp("pwd ", s, 4))
		return (1);
	if (!ft_strncmp("unset ", s, 6))
		return (1);
	return (0);
}

static void	handle_output_redirection(t_c *cmd, char **s)
{
	if (**s == '>')
	{
		if (cmd->nout)
			free(cmd->nout);
		if ((*s)[1] == '>' && ft_strchr(" \"'", (*s)[2]))
			cmd->nout = ft_substr(*s, 3, ft_strlenstr(*s + 3, " \"'"));
		else if ((*s)[1] == '>' || ft_strchr(" \"'", (*s)[1]))
			cmd->nout = ft_substr(*s, 2, ft_strlenstr(*s + 2, " \"'"));
		else
			cmd->nout = ft_substr(*s, 1, ft_strlenstr(*s + 1, " \"'"));
		while (**s && !ft_isalpha(**s))
			(*s)++;
		(*s) += ft_strlenstr(*s, " \"'");
	}
}

static void	handle_input_redirection(t_c *cmd, char **s)
{
	if (**s == '<')
	{
		if (cmd->nin || cmd->heredoc)
			ft_freebulk("ss", cmd->nin, cmd->heredoc);
		if ((*s)[1] == '<' && ft_strchr(" \"'", (*s)[2]))
			cmd->heredoc = ft_substr(*s, 3, ft_strlenstr(*s + 3, " \"'"));
		else if ((*s)[1] == '<' || ft_strchr(" \"'", (*s)[1]))
			cmd->heredoc = ft_substr(*s, 2, ft_strlenstr(*s + 2, " \"'"));
		else
			cmd->nin = ft_substr(*s, 1, ft_strlenstr(*s + 1, " \"'"));
		while (**s && !ft_isalpha(**s))
			(*s)++;
		(*s) += ft_strlenstr(*s, " \"'");
	}
}

static char	*ft_redsimpl(t_c *cmd, char *s)
{
	char	*rt;
	size_t	i;

	i = 0;
	rt = ft_calloc(ft_strlen(s, 0), sizeof(char));
	while (*s)
	{
		if (*s == '>')
		{
			handle_output_redirection(cmd, &s);
		}
		else if (*s == '<')
		{
			handle_input_redirection(cmd, &s);
		}
		else
		{
			rt[i++] = *s;
			s++;
		}
	}
	return (rt);
}

void	ft_prep(t_b *tb)
{
	char	**lst;
	char	*tmp;
	int		i;

	lst = ft_splitpip(tb->rd, '|');
	tb->max = ft_lstlen(lst);
	tb->cmd = ft_calloc(tb->max, sizeof(t_c));
	i = -1;
	while (++i < tb->max)
	{
		tb->cmd[i].orig = tb;
		tmp = ft_redsimpl(&tb->cmd[i], lst[i]);
		if (!ft_cbuiltin(lst[i]) && ft_strlenstr
			(lst[i], "<>") == ft_strlen(lst[i], 0))
			tmp = lst[i];
		tb->cmd[i].path = ft_path(ft_substr
				(tmp, 0, ft_strlen(tmp, 32)), tb->penv);
		tb->cmd[i].cmd = ft_splitpip(tmp, 32);
		if (tmp != lst[i])
			free(tmp);
	}
	ft_freelst(lst);
}

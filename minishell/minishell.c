/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/14 13:56:56 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

static char	**ft_cenv(void)
{
	char	**tmp;

	tmp = ft_calloc(5, sizeof(char *));
	tmp[0] = ft_strjoin("PWD=", getcwd(tmp[0], 1024), 3);
	tmp[1] = ft_strjoin("OLDPWD=", getcwd(tmp[1], 1024), 3);
	tmp[2] = ft_strjoin("SHLVL=1", NULL, 1);
	tmp[3] = ft_strjoin("PATH=", "/usr/sbin:/usr/bin:/sbin:/bin", 1);
	return (tmp);
}

static int	ft_check(char *s, int fd)
{
	if (ft_skipchar(s, 32) == ft_strlen(s, 0))
		return (1);
	add_history(s);
	ft_printf(fd, "%s\n", s);
	if (ft_verifwarg(s))
		return (1);
	if (ft_verifcote(s))
		return (1);
	if (ft_verifpip(s))
		return (ft_printf(2, "syntax error near unexpected token `|'\n"));
	if (ft_verifredir(s))
		return (1);
	return (0);
}

static void	ft_init(t_b *tb, char ***env)
{
	if (!*env[0] || !env)
		*env = ft_cenv();
	tb->env = envcpy(*env);
	tb->secret_env = envcpy(*env);
	tb->lenv = ft_lstlen(*env);
	tb->err = open("/tmp/error_val", O_RDWR | O_CREAT | O_TRUNC, 0644);
	tb->hist = open("/tmp/history", O_RDWR | O_CREAT | O_APPEND, 0644);
	tb->i = 0;
	ft_printf(tb->err, "0\n");
}

int	main(int ac, char **av, char **env)
{
	t_b		tb;

	ft_signal();
	ft_init(&tb, &env);
	while (ac && av)
	{
		tb.rd = readline("minishell> ");
		if (!tb.rd || !ft_strncmp("exit", tb.rd + ft_skipchar(tb.rd, 32), 5))
		{
			rl_clear_history();
			ft_freebulk("sllff", tb.rd, tb.env, tb.secret_env, tb.err, tb.hist);
			unlink("/tmp/error_val");
			return (0);
		}
		if (ft_check(tb.rd, tb.hist))
			free(tb.rd);
		else
		{
			tb.rd = ft_strsimp(tb.rd);
			tb.rd = ft_convarg(tb.rd);
			tb.rd = ft_strsimp(tb.rd);
			mini(&tb);
			free(tb.rd);
		}
	}
}

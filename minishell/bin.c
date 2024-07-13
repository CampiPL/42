/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:18:16 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 21:13:08 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	magic_box(char *path, char **args, t_b *mini)
{
	int	ret;

	g_sig.pid = fork();
	if (g_sig.pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
			execve(path, args, mini->env);
	}
	else
		waitpid(g_sig.pid, &ret, 0);
}

static char	*path_join(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	tmp = strjoin(s1, "/");
	path = strjoin(tmp, s2);
	ft_memdel(tmp);
	return (path);
}

static char	*check_dir(char *bin, char *command)
{
	DIR				*folder;
	struct dirent	*item;
	char			*path;

	path = NULL;
	folder = opendir(bin);
	if (!folder)
		return (NULL);
	item = readdir(folder);
	while (item)
	{
		if (ft_strcmp(item->d_name, command) == 0)
			path = path_join(bin, item->d_name);
		item = readdir(folder);
	}
	closedir(folder);
	return (path);
}

void	exec_bin(char **cmdarg, t_b *mini)
{
	int		i;
	char	**bin;
	char	*path;

	i = 0;
	while (mini->env && mini->env[i]
		&& ft_strncmp(mini->env[i], "PATH=", 5) != 0)
		i++;
	if (mini->env == NULL || mini->env[i + 1] == NULL)
		magic_box(cmdarg[0], cmdarg, mini);
	bin = ft_split(mini->env[i], ':');
	if (!cmdarg[0] && !bin[0])
		exit (EXIT_FAILURE);
	i = 1;
	path = check_dir(bin[0] + 5, cmdarg[0]);
	while (cmdarg[0] && bin[i] && path == NULL)
		path = check_dir(bin[i++], cmdarg[0]);
	if (path != NULL)
		magic_box(path, cmdarg, mini);
	else
		magic_box(cmdarg[0], cmdarg, mini);
	free_cmdarg(bin);
	ft_memdel(path);
}

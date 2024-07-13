/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:08:51 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 13:49:01 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char **args)
{
	ft_putstr_fd("cd: ", 2);
	if (args[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(args[1], 2);
}

static char	*get_env_path(char **env, const char *var, size_t len)
{
	char	*oldpwd;
	int		i;
	int		j;
	int		k;
	int		s_alloc;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0)
		{
			s_alloc = strlen(env[i]) - len;
			oldpwd = malloc(sizeof(char) * s_alloc + 1);
			if (!oldpwd)
				return (NULL);
			k = 0;
			j = 0;
			while (env[i][k++])
			{
				if (k > (int)len)
					oldpwd[j++] = env[i][k];
			}
			oldpwd[j] = '\0';
			return (oldpwd);
		}
		i++;
	}
	return (NULL);
}

static int	update_oldpwd(char **env)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (1);
	oldpwd = strjoin("OLDPWD=", cwd);
	if (!oldpwd)
		return (1);
	if (is_in_env(env, oldpwd) == 0)
		env_add(oldpwd, &env);
	ft_memdel(oldpwd);
	return (0);
}

static void	go_to_path(int option, char **env)
{
	char	*env_path;

	env_path = NULL;
	if (option == 0)
	{
		update_oldpwd(env);
		env_path = get_env_path(env, "HOME", 4);
		if (!env_path)
		{
			ft_putendl_fd("minishell : cd: HOME not set", 1);
			return ;
		}
	}
	else if (option == 1)
	{
		env_path = get_env_path(env, "OLDPWD", 6);
		if (!env_path)
		{
			ft_putendl_fd("minishell : cd: OLDPWD not set", 1);
			return ;
		}
		update_oldpwd(env);
	}
	chdir(env_path);
	ft_memdel(env_path);
}

void	ft_cd(char **args, char **env)
{
	int		cd_ret;

	if (!args[1])
		go_to_path(0, env);
	else if (strcmp(args[1], "-") == 0)
		go_to_path(1, env);
	else
	{
		update_oldpwd(env);
		cd_ret = chdir(args[1]);
		if (cd_ret != 0)
			print_error(args);
	}
}

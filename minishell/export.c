/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:06:49 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 20:24:10 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(int error, const char *arg)
{
	int		i;

	if (error == -1)
		ft_putstr_fd("export: not valid in this context: ", 2);
	else if (error == 0 || error == -3)
		ft_putstr_fd("export: not a valid identifier: ", 2);
	i = 0;
	while (arg[i] && (arg[i] != '=' || error == -3))
	{
		write(2, &arg[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	env_add(char *value, char ***env)
{
	int		count;
	char	**new_env;
	int		i;

	count = 0;
	while ((*env)[count])
		count++;
	new_env = ft_calloc((count + 2), sizeof(char *));
	if (!new_env)
		return ;
	i = 0;
	while (i < count)
	{
		new_env[i] = ft_strdup((*env)[i]);
		i++;
	}
	new_env[count] = ft_strdup(value);
	ft_freelst(*env);
	*env = new_env;
}

static char	*get_env_name(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '=' && strlen(src) < BUFF_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_in_env(char **env, char *args)
{
	char	var_name[BUFF_SIZE];
	char	env_name[BUFF_SIZE];
	int		i;

	get_env_name(var_name, args);
	i = 0;
	while (env[i])
	{
		get_env_name(env_name, env[i]);
		if (strcmp(var_name, env_name) == 0)
		{
			env[i] = args;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_export(char **args, t_b *mini)
{
	int		new_env;
	int		error_ret;

	new_env = 0;
	if (!args[1])
	{
		print_sorted_env(mini->secret_env);
		return ;
	}
	else
	{
		error_ret = is_valid_env(args[1]);
		if (args[1][0] == '=')
			error_ret = -3;
		if (error_ret <= 0)
			return (print_error(error_ret, args[1]));
		if (error_ret == 2)
			new_env = 1;
		else
			new_env = is_in_env(mini->env, args[1]);
		if (new_env == 0)
		{
			if (error_ret == 1)
				env_add(args[1], &mini->env);
			env_add(args[1], &mini->secret_env);
		}
	}
}

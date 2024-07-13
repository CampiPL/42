/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:09:00 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 17:43:10 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		ft_putendl_fd(env[i], 1);
		i++;
	}
	if (env[i])
		ft_putendl_fd(env[i], 1);
}

int	str_env_len(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	sort_env(char **tb, int env_len)
{
	int		ordered;
	int		i;
	char	*tmp;

	ordered = 0;
	while (tb && ordered == 0)
	{
		ordered = 1;
		i = 0;
		while (i < env_len - 1)
		{
			if (ft_strcmp(tb[i], tb[i + 1]) > 0)
			{
				tmp = tb[i];
				tb[i] = tb[i + 1];
				tb[i + 1] = tmp;
				ordered = 0;
			}
			i++;
		}
		env_len--;
	}
}

int	is_valid_env(const char *env)
{
	int		i;

	i = 0;
	if (ft_isdigit(env[i]) == 1)
		return (0);
	while (env[i] && env[i] != '=')
	{
		if (ft_isalnum(env[i]) == 0)
			return (-1);
		i++;
	}
	if (env[i] != '=')
		return (2);
	return (1);
}

void	print_sorted_env(char **env)
{
	char	**tb;
	int		i;

	tb = env;
	sort_env(tb, str_env_len(tb));
	i = 0;
	while (tb[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(tb[i], 1);
		i++;
	}
}

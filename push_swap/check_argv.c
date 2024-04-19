/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:17:59 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/19 11:51:55 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && num[1])
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_contains(char **args, char *num, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == ft_atoi(num))
			return (0);
		i++;
	}
	return (1);
}

void	check_argv(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i++;
		args = argv;
	}
	while (args[i])
	{
		if (!ft_isnum(args[i]) || !ft_contains(args, args[i], i)
			|| ft_atoi(args[i]) < -2147483648 || ft_atoi(args[i]) > 2147483647)
			ft_error();
		i++;
	}
	if (argc == 2)
		ft_free_args(args);
}

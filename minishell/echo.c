/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:09:32 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/13 12:09:33 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

static	int	nb_args(char **args)
{
	int		size;

	size = 0;
	while (args[size])
	{
		// printf("%s\n", args[size]);
		size++;
	}
	// printf("Size: %i\n", size);
	return (size);
}

void	ft_echo(char **args)
{
	int		i;
	int		n_option;

	// i = 0;
	// while (args && args[i])
	// 	printf("%s\n", args[i++]);
	i = 1;
	n_option = 0;
	if (nb_args(args) > 1)
	{
		// printf("Tu nie wchodze\n");
		while (args[i] && strcmp(args[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
}

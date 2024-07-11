/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:16:55 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/11 18:29:32 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	free_cmd(t_cmd *start)
{
	while (start && start->next)
	{
		ft_memdel(start->str);
		start = start->next;
		ft_memdel(start->prev);
	}
	if (start)
	{
		ft_memdel(start->str);
		ft_memdel(start);
	}
}

void	free_cmdarg(char **cmdarg)
{
	int	i;

	i = 0;
	while (cmdarg[i])
	{
		if (cmdarg[i])
			ft_memdel(cmdarg[i]);
		i++;
	}
	if (cmdarg)
		ft_memdel(cmdarg);
}

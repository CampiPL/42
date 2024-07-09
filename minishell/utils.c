/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:58:10 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/09 17:32:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	next_alloc(char *line, int *i)
{
	int		j;

	j = 0;
	while (line[*i + j] && line[*i + j] != ' ')
		j++;
	return (j + 1);
}

t_cmd	*next_run(t_cmd *cmd)
{
	while (cmd && cmd->type != CMD)
		cmd = cmd->next;
	return (cmd);
}

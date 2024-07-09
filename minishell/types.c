/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:51:42 by ubuntu            #+#    #+#             */
/*   Updated: 2024/07/09 17:22:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_arg(t_cmd *cmd)
{
	if (ft_strcmp(cmd->str, ">") == 0)
		cmd->type = TRUNC;
	else if (ft_strcmp(cmd->str, ">>") == 0)
		cmd->type = APPEND;
	else if (ft_strcmp(cmd->str, "<") == 0)
		cmd->type = INPUT;
	else if (ft_strcmp(cmd->str, "|") == 0)
		cmd->type = PIPE;
	else if (ft_strcmp(cmd->str, ";") == 0)
		cmd->type = END;
	else if (cmd->prev == NULL || cmd->prev->type >= TRUNC)
		cmd->type = CMD;
	else
		cmd->type = ARG;
}

int	is_type(t_cmd *cmd, int type)
{
	if (cmd && cmd->type == type)
		return (1);
	else
		return (0);
}

int	is_types(t_cmd *cmd, char *types)
{
	if (ft_strchr(types, 'X') && is_type(cmd, CMD))
		return (1);
	else if (ft_strchr(types, 'x') && is_type(cmd, ARG))
		return (1);
	else if (ft_strchr(types, 'T') && is_type(cmd, TRUNC))
		return (1);
	else if (ft_strchr(types, 'A') && is_type(cmd, APPEND))
		return (1);
	else if (ft_strchr(types, 'I') && is_type(cmd, INPUT))
		return (1);
	else if (ft_strchr(types, 'P') && is_type(cmd, PIPE))
		return (1);
	else if (ft_strchr(types, 'E') && is_type(cmd, END))
		return (1);
	return (0);
}

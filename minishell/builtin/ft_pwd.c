/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:30:07 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/04 14:38:16 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_pwd()
{
	char	*var;

	var = ft_calloc(1024, sizeof(char));
	if (!var)
		return ;
	var = getcwd(var, 1024);
	ft_printf("%s\n", var);
	free(var);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:29:44 by rmakhlou          #+#    #+#             */
/*   Updated: 2023/01/12 12:11:43 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

void	ft_env(char **lst)
{
	if (!lst)
		return (ft_putstr_fd("Environment not found\n", 1));
	while (lst && *lst++)
		printf("%s\n", *lst);
	g_core = 0;
}

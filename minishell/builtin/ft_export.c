/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:29:58 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/19 11:45:07 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_export(char **lst, char *s)
{
	char	**rt;
	size_t	i;

	if (!lst)
	{
		rt = ft_malloc(2, sizeof(char *));
		rt[0] = ft_strdup(s);
		return (rt);
	}
	rt = ft_calloc((ft_sizelst(lst) + 1), sizeof(char *));
	i = -1;
	while (lst && lst[++i])
		rt[i] = ft_strdup(lst[i]);
	rt[i] = ft_strdup(s);
	ft_freelst(lst);
	return (rt);
}

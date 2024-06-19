/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:30:20 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/19 11:45:27 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_unset(char **lst, char *s)
{
	char	**rt;
	size_t	i;

	if (!lst)
		return (NULL);
	if (!s)
		rt = ft_calloc((ft_sizelst(lst) + 1), sizeof(char *));
	else
		rt = ft_calloc(ft_sizelst(lst) * sizeof(char *));
	i = -1;
	while (lst && lst[++i])
	{
		if (ft_strncmp(lst[i], s, ft_strlen(s, 0)))
			i++;
		else
			rt[i] = ft_strdup(lst[i]);
	}
	ft_freelst(lst);
	return (rt);
}

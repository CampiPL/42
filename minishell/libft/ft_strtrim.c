/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:27 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/02/07 18:55:28 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	st = 0;
	end = ft_strlen(s1, 0) - 1;
	while (st <= end && ft_strchr(set, s1[st]))
		st++;
	while (st <= end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, st, end - st + 1));
}

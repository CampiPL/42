/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <rmakhlou@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:55:16 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/07 16:17:23 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*a;

	i = -1;
	if (!s)
		return (NULL);
	a = malloc(sizeof(char) * (ft_strlen(s, 0) + 1));
	if (!a)
		return (NULL);
	while (s[++i])
		a[i] = f(i, s[i]);
	a[i] = 0;
	return (a);
}

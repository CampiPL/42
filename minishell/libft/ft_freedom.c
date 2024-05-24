/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 00:47:31 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/07 16:15:49 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelst(char **lst)
{
	int	i;

	i = 0;
	if (!lst)
		return ;
	while (lst[i])
		free(lst[i++]);
	free(lst);
}

void	ft_freebulk(const char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	while (s && *s)
	{
		if (*s == 's')
			free(va_arg(ap, char **));
		else if (*s == 'l')
			ft_freelst(va_arg(ap, char **));
		else if (*s == 'i')
			free(va_arg(ap, int *));
		else if (*s == 'f')
			close(va_arg(ap, int));
		s++;
	}
	va_end(ap);
}

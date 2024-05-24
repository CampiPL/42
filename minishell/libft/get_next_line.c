/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:02:17 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/07 16:16:21 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(int fd, char *sv)
{
	char	*rd;
	int		b;

	b = 1;
	while (ft_strchr(sv, '\n') == 0 && b > 0)
	{
		rd = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!rd)
			return (NULL);
		b = read(fd, rd, BUFFER_SIZE);
		if (b < 0)
			return (free(rd), NULL);
		rd[b] = 0;
		sv = ft_strjoin(sv, rd, 6);
	}
	return (sv);
}

char	*get_next_line(int fd)
{
	char		*tp;
	char		*rt;
	static char	*sv;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tp = ft_read(fd, sv);
	rt = ft_substr(tp, 0, ft_strlen(tp, '\n') + 1);
	sv = ft_substr(tp, ft_strlen(rt, '\0'), ft_strlen(tp, '\0'));
	free(tp);
	if (!ft_strchr(rt, '\n') || (sv && sv[0] == 0))
	{
		free(sv);
		sv = NULL;
	}
	if (!rt[0])
		return (free(rt), NULL);
	return (rt);
}

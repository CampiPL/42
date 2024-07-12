/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geterrno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:58:49 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/12 11:57:32 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_seterrno(int err)
{
	int	fd;

	fd = open("/tmp/error_val", O_RDWR | O_CREAT | O_TRUNC, 0777);
	ft_printf(fd, "%i", err);
	close(fd);
}

char	*ft_geterrno(void)
{
	int		fd;
	char	*rt;

	fd = open("/tmp/error_val", O_RDONLY);
	rt = get_next_line(fd);
	close(fd);
	return (rt);
}

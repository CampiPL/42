/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:14:58 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/01 14:14:59 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main() {
    char c = 'A';
    ft_putchar_fd(c, STDOUT_FILENO);
    ft_putchar_fd('\n', STDOUT_FILENO);
    return 0;
}
*/

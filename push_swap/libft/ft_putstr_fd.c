/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:18:13 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/01 14:18:14 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s++, 1);
	}
}
/*
int main() {
    char *s = "Hello, world!";
    ft_putstr_fd(s, STDOUT_FILENO); // Output to standard output (console)
    ft_putstr_fd("\n", STDOUT_FILENO); // Output a newline character
    return 0;
}
*/

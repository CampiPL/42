/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:42:54 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 13:42:55 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i++] = '\0';
	}
}
/*
int main() {
    char str[50] = "Hello, world!";
    printf("Przed bzero: %s\n", str);
    ft_bzero(str, 5);
    printf("Po bzero: %s\n", str);
    return 0;
}
*/

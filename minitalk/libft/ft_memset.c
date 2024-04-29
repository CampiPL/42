/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:26:37 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 13:26:38 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i++] = (unsigned char)c;
	}
	return (s);
}
/*
int main() {
    char str[50] = "Hello, world!";
    printf("Przed memset: %s\n", str);
    ft_memset(str, '?', 5);
    printf("Po memset: %s\n", str);
    return 0;
}
*/

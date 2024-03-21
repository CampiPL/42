/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:59:23 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 14:59:24 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;
	size_t		i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main() {
    char str[] = "Hello, world!";
    char *znak = memchr(str, 'o', sizeof(str));
    if (znak != NULL) {
        printf("Znaleziono znak: %c\n", *znak);
    } else {
        printf("Nie znaleziono znaku\n");
    }
    return 0;
}
*/

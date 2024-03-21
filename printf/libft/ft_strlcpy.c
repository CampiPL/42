/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:55:44 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 13:55:45 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
/*
int main() {
    char src[] = "Hello, world!";
    char dest[50];
    size_t copied = ft_strlcpy(dest, src, sizeof(dest));
    printf("Skopiowano: %s\n", dest);
    printf("Liczba skopiowanych znakow: %zu\n", copied);
    return 0;
}
*/

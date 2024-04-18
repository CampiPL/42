/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:10:24 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 12:10:25 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char		*p_dest;
	size_t		i;
	const char	*p_src;

	p_dest = dest;
	p_src = src;
	i = 0;
	while (i < num)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
/*
int main() {
    char src[50] = "Hello, world!";
    char dest[50];
    ft_memcpy(dest, src, 5);
    printf("Skopiowano: %s\n", dest);
    return 0;
}
*/

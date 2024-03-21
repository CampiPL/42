/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:44 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 13:37:46 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*p_dest;
	const char	*p_src;
	char		temp[50];
	size_t		i;

	p_dest = dest;
	p_src = src;
	i = 0;
	while (i < n)
	{
		temp[i] = p_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		p_dest[i] = temp[i];
		i++;
	}
	return (dest);
}
/*
int main() {
    char src[50] = "Hello, world!";
    char dest[50];
    ft_memmove(dest, src, 5);
    printf("Skopiowano: %s\n", dest);
    return 0;
}
*/

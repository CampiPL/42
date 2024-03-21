/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:09:25 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 15:09:26 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
/*
int main() {
    char str1[] = "Hello, world!X";
    char str2[] = "Hello, world!X";
    int result = ft_memcmp(str1, str2, sizeof(str1) + 10);
    if (result == 0) {
        printf("Obszary pamięci są równe\n");
    } else if (result > 0) {
        printf("Pierwszy obszar pamięci jest większy\n");
    } else {
        printf("Drugi obszar pamięci jest większy\n");
    }
    return 0;
}
*/

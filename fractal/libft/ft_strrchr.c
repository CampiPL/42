/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:45:15 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 14:45:16 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
int main() {
    char str[] = "Hello, world!";
    char *znak = ft_strrchr(str, 'o');
    if (znak != NULL) {
        printf("Znaleziono znak: %c\n", *znak);
    } else {
        printf("Nie znaleziono znaku\n");
    }
    return 0;
}
*/

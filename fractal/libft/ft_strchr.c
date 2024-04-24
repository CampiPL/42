/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:41:10 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 14:41:10 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/*
int main() {
    char str[] = "Hello, world!";
    char *znak = ft_strchr(str, 'o');
    if (znak != NULL) {
        printf("Znaleziono znak: %c\n", *znak);
    } else {
        printf("Nie znaleziono znaku\n");
    }
    return 0;
}
*/

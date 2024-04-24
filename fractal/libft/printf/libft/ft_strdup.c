/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:58:38 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/29 10:58:39 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	ptr = (char *)malloc(len + 1);
	if (ptr != NULL)
	{
		while (i < len)
		{
			ptr[i] = s[i];
			i++;
		}
		ptr[len] = '\0';
	}
	return (ptr);
}
/*
int main() {
    const char *str = "Hello, world!";
    char *dup = ft_strdup(str);
    if (dup != NULL) {
        printf("Duplikat: %s\n", dup);
        free(dup);
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/

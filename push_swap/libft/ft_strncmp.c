/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:53:19 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 14:53:19 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (0);
}
/*
int main() {
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    int result = ft_strncmp(str1, str2, 5);
    if (result == 0) {
        printf("Ciągi znaków są równe\n");
    } else if (result > 0) {
        printf("Pierwszy ciąg znaków jest większy\n");
    } else {
        printf("Drugi ciąg znaków jest większy\n");
    }
    return 0;
}
*/

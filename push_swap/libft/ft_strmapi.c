/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:07:59 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/01 11:08:00 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*result;
	size_t	i;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
static char	add_index(unsigned int index, char c)
{
	return (c + index);
}

int main() {
    const char *s = "Hello, world!";
    char *str = ft_strmapi(s, add_index);
    if (str != NULL) {
        printf("Original string: %s\nModified string: %s\n", s, str);
        free(str);
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/

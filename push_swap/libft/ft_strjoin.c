/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:17:56 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/01 16:17:58 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, s1_len);
	ft_memcpy(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}
/*
int main() {
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *joined = ft_strjoin(s1, s2);
    if (joined != NULL) {
        printf("Joined string: %s\n", joined);
        free(joined);
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/

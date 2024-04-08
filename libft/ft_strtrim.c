/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:49:54 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/08 12:50:09 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	trimmed_len;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start < ft_strlen(s1) && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	trimmed_len = end - start + 1;
	trimmed = (char *)malloc(trimmed_len + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, s1 + start, trimmed_len);
	trimmed[trimmed_len] = '\0';
	return (trimmed);
}
/*
int main() {
    const char *s1 = "";
    const char *set = "123";
    char *trimmed = ft_strtrim(s1, set);
    if (trimmed != NULL) {
        printf("Trimmed string: %s\n", trimmed);
        free(trimmed);
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/
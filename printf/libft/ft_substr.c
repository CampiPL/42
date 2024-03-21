/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:12:11 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/29 11:12:12 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	finish = 0;
	if (start < slen)
		finish = slen - start;
	else
		return (ft_strdup(""));
	if (finish > len)
		finish = len;
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}
/*
int main() {
    const char *s = "Hello, world!";
    unsigned int start = 7;
    size_t len = 5;
    char *sub = ft_substr(s, start, len);
    if (sub != NULL) {
        printf("Substring: %s\n", sub);
        free(sub);
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/

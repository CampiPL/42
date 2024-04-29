/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:50:52 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/29 15:50:53 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	help2(char **result, size_t index)
{
	size_t	j;

	j = 0;
	while (j < index)
		free(result[j++]);
	free(result);
}

static int	help(const char *s, char c, char **result, size_t index)
{
	size_t	i;
	size_t	start;

	start = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (i == ft_strlen(s) - 1 || s[i + 1] == c))
		{
			result[index] = ft_substr(s, start, i - start + 1);
			if (result[index] == NULL)
			{
				help2(result, index);
				return (1);
			}
			index++;
		}
		i++;
	}
	return (0);
}

static char	**split_words(const char *s, char c, size_t num_words)
{
	char	**result;
	size_t	index;

	result = (char **)malloc((num_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	index = 0;
	if (help(s, c, result, index) == 1)
		return (NULL);
	result[num_words] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	s_len;
	size_t	num_words;
	char	**result;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	num_words = 0;
	i = 0;
	while (i < s_len)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			num_words++;
		i++;
	}
	result = split_words(s, c, num_words);
	return (result);
	free(result);
}
/*
int main() {
    const char *s = "Hello, world!";
    char **split = ft_split(s, ' ');
    if (split != NULL) {
        for (size_t i = 0; split[i] != NULL; i++) {
            printf("Split string %zu: %s\n", i, split[i]);
        }
    } else {
        printf("Nie udało się zaalokować pamięci\n");
    }
    return 0;
}
*/

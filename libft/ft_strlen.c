/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:37:46 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 12:37:47 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	dlugosc;

	dlugosc = 0;
	while (s[dlugosc] != '\0')
	{
		dlugosc++;
	}
	return (dlugosc);
}
/*
int main() {
    char str[] = "Hello, world!";
    size_t dlugosc = ft_strlen(str);
    printf("Dlugosc ciagu znakow: %zu\n", dlugosc);
    return 0;
}
*/

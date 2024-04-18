/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:00:00 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/01 12:00:01 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
static void	print_index(unsigned int index, char *c)
{
	printf("Character at index %u: %c\n", index, *c);
}

int main() {
    char s[] = "Hello, world!";
    ft_striteri(s, print_index);
    return 0;
}
*/

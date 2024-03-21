/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:39:45 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 14:39:46 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 'a' - 'A');
	}
	else
	{
		return (c);
	}
}
/*
int main() {
    char znak = 'H';
    printf("Przed tolower: %c\n", znak);
    znak = ft_tolower(znak);
    printf("Po tolower: %c\n", znak);
    return 0;
}
*/

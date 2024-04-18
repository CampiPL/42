/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:35:37 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/28 14:35:39 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 'A');
	}
	else
	{
		return (c);
	}
}
/*
int main() {
    char znak = 'r';
    printf("Przed toupper: %c\n", znak);
    znak = ft_toupper(znak);
    printf("Po toupper: %c\n", znak);
    return 0;
}
*/

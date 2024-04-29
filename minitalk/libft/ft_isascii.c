/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:20:43 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 12:20:46 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int main() {
    char znak = 'A';

    printf("%d\n", ft_isascii(znak));


    znak = 128;
    
    printf("%d\n", ft_isascii(znak));

    return 0;
}
*/

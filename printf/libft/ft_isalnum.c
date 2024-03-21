/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:06:00 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 12:06:01 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int main() {
    char znak = 'B';
    
    printf("%d\n", ft_isalnum(znak));

    znak = '5';

    printf("%d\n", ft_isalnum(znak));
    
    znak = '\n';

    printf("%d\n", ft_isalnum(znak));

    return 0;
}
*/

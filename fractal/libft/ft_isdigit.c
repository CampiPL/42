/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:28:49 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 11:28:51 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int main()
{
    char znak = '5';
    
    printf("%d\n", ft_isdigit(znak));

    znak = 'A';
    
    printf("%d\n", ft_isdigit(znak));
    
    return 0;
}
*/

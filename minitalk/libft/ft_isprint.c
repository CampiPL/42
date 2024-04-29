/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:29:34 by jdepka            #+#    #+#             */
/*   Updated: 2024/02/27 12:29:36 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(unsigned char c)
{
	return (c >= 32 && c <= 126);
}
/*
int main()
{
    char znak = 'A';
    
    printf("%d\n", ft_isprint(znak));
    

    znak = '\n';
    
    printf("%d\n", ft_isprint(znak));

    return 0;
}
*/

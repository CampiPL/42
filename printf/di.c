/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:36:30 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/13 12:36:31 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	di(int num)
{
	int	count;

	count = 0;
	ft_putnbr_fd(num, STDOUT_FILENO);
	if (num < 0)
	{
		count++;
		num = -num;
	}
	count++;
	num /= 10;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

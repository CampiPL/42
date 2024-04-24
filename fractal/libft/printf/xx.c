/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:07:12 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/13 12:07:13 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putx_fd(unsigned int n, int fd)
{
	const char	*hex_digits = "0123456789ABCDEF";
	char		str[13];
	int			is_neg;
	int			length;

	is_neg = (n < 0);
	ft_bzero(str, 13);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = hex_digits[n % 16];
		n = (n / 16);
	}
	if (is_neg)
		str[length] = '-';
	else if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}

int	xx(unsigned int num)
{
	int	count;

	count = 0;
	ft_putx_fd(num, STDOUT_FILENO);
	count++;
	num /= 16;
	while (num != 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}

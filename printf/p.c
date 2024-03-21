/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:11:28 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/13 12:11:28 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_pointer_length(void *ptr)
{
	int					length;
	unsigned long long	value;

	value = (unsigned long long) ptr / 16;
	length = 1;
	while (value != 0)
	{
		length++;
		value /= 16;
	}
	return (length);
}

static void	ft_putp(unsigned long ptr)
{
	static char	digits[] = "0123456789abcdef";

	if (ptr >= 16)
		ft_putp(ptr / 16);
	write(STDOUT_FILENO, &digits[ptr % 16], 1);
}

int	p(void *ptr)
{
	int		count;

	if (ptr == NULL)
		return (write(STDOUT_FILENO, "(nil)", 5));
	write(STDOUT_FILENO, "0x", 2);
	ft_putp((unsigned long) ptr);
	count = get_pointer_length(ptr);
	return (count + 2);
}

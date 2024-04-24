/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:36:24 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/13 12:36:25 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s(const char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		ft_putchar_fd(*str, STDOUT_FILENO);
		str++;
		count++;
	}
	return (count);
}

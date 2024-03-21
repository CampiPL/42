/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:41:49 by jdepka            #+#    #+#             */
/*   Updated: 2024/03/11 11:41:50 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	c(int c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

static int	percent(void)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}

static int	el(const char *format)
{
	ft_putchar_fd('%', STDOUT_FILENO);
	ft_putchar_fd(*format, STDOUT_FILENO);
	return (2);
}

static int	help(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += c(va_arg(args, int));
	else if (*format == 's')
		count += s(va_arg(args, const char *));
	else if (*format == 'p')
		count += p(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		count += di(va_arg(args, int));
	else if (*format == 'u')
		count += u(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += x(va_arg(args, unsigned int));
	else if (*format == 'X')
		count += xx(va_arg(args, unsigned int));
	else if (*format == '%')
		count += percent();
	else
		count += el(format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += help(format, args);
		}
		else
		{
			ft_putchar_fd(*format, STDOUT_FILENO);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

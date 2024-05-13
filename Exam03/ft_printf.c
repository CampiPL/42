/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:04:48 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/13 13:15:27 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static void	put_str(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
		*count += write(1, str++, 1);
}

static void	put_nbr(long long int nbr, int base, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*count = write(1, "-", 1);
	}
	if (nbr >= base)
		put_nbr((nbr / base), base, count);
	*count += write(1, &hex[nbr % base], 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(args, char *), &count);
			else if (*format == 'd')
				put_nbr((long long int)va_arg(args, int), 10, &count);
			else if (*format == 'x')
				put_nbr((long long int)va_arg(args, unsigned int), 16, &count);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	return (va_end(args), count);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;

	size = 0;

	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}
*/
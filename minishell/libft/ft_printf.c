/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:21:20 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/11 20:37:09 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memjoin(void *s1, void *s2, int a, int *b)
{
	int		i;
	char	*t;
	char	*t1;
	char	*t2;

	i = -1;
	t1 = (char *)s1;
	t2 = (char *)s2;
	t = malloc((*b) * sizeof(char));
	if (!t)
		return (NULL);
	while (++i < a)
		t[i] = t1[i];
	i--;
	while (++i < *b)
		t[i] = t2[i - a];
	ft_freebulk("ss", s1, s2);
	return ((void *)t);
}

static char	*ft_cstr(char c, int *i)
{
	char	*rt;

	rt = malloc(1 * sizeof(char));
	rt[0] = c;
	*i += 1;
	return (rt);
}

static char	*ft_strdup2(char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	if (s && !ft_strncmp(s, "0x0", 3))
		return (free(s), ft_strdup("(nil)"));
	return (ft_strdup(s));
}

static char	*vtype(const char *s, va_list ap, int *i)
{
	char	*t;

	t = NULL;
	if (s && *s == 'c')
		t = ft_cstr(va_arg(ap, int), i);
	else if (s && *s == 's')
		t = ft_strdup2(va_arg(ap, char *));
	else if (s && (*s == 'd' || *s == 'i'))
		t = ft_itoa(va_arg(ap, int));
	else if (s && *s == 'u')
		t = ft_ultoa_b(va_arg(ap, unsigned int), "0123456789");
	else if (s && *s == 'x')
		t = ft_ultoa_b(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (s && *s == 'X')
		t = ft_ultoa_b(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (s && *s == 'p')
		t = ft_strjoin("0x", ft_ultoa_b(va_arg
					(ap, unsigned long int), "0123456789abcdef"));
	else if (s && *s == '%')
		t = ft_cstr('%', i);
	if (s && *s == 'p' && !ft_strncmp(t, "0x0", 3))
		t = ft_strdup2(t);
	if (s && *s != 'c' && *s != '%')
		*i += ft_strlen(t, 0);
	return (t);
}

int	ft_printf(int fd, const char *s, ...)
{
	char	*rs;
	int		i;
	int		tmpi;
	va_list	ap;

	rs = NULL;
	va_start(ap, s);
	i = 0;
	while (s && *s)
	{
		tmpi = i;
		if (s[1] && *s == '%')
			rs = ft_memjoin(rs, vtype(++s, ap, &i), tmpi, &i);
		else if (*s != '%')
		{
			i += ft_strlen(s, '%');
			rs = ft_memjoin(rs, ft_substr(s, 0, i - tmpi), tmpi, &i);
			s += i - tmpi - 1;
		}
		s++;
	}
	write (fd, rs, i);
	free(rs);
	va_end(ap);
	return (i);
}

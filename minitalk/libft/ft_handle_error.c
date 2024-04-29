/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:03:00 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/29 11:03:49 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_error(char *content)
{
	ft_putstr_fd(content, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

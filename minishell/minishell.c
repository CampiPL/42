/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/19 13:07:48 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_b *tb)
{

}

int	main(int argc, char *argv[], char **env)
{
	t_b	tb;
//	char *s;
	ft_signal();
	while (1)
	{
		tb.rd = readline("Minishell> ");
		if (!tb.rd || !ft_strncmp("exit", tb.rd + ft_skipchar(tb.rd, 32), 4))
		{
			rl_clear_history();
			free(tb.rd);
			return (0);
		}
		if (ft_strlen(tb.rd, 0) != ft_skipchar(tb.rd, 32))
			add_history(tb.rd);
		if (/*!ft_skipchar(tb.rd, 32) ||*/ ft_verifcote(tb.rd)
			|| ft_verifwarg(tb.rd) || ft_verifpip(tb.rd)
			|| ft_verifredir(tb.rd))
			free(tb.rd);
		else
		{
			tb.rd = ft_strsimp(tb.rd);
			//ft_verifpip(tb.rd, &tb);
			minishell(&tb);
			if (!tb.rd || !ft_strncmp("exit", tb.rd, 4))
			{
				rl_clear_history();
				free(tb.rd);
				exit(0);
			}
			printf("-%s\n", tb.rd);
			free(tb.rd);
		}
	}
}

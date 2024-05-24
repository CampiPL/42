/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:51:39 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/05/24 15:45:27 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int main()
{
	t_b tb;
//	int	id;
	//int 	a;

	ft_signal();
	while(1)
	{
		tb.rd = readline("Minishell> ");
		add_history(tb.rd);
	//	s = ft_verifcote(s);
		if (ft_verifcote(tb.rd))
			printf("Error: unclosed cote\n");
		else
		{
			tb.rd = ft_strsimp(tb.rd);
//		        ft_verifpip(tb.rd, &tb);
			if (!tb.rd || !ft_strncmp("exit", tb.rd, 4))
			{
			rl_clear_history();
			free(tb.rd);
			exit(0);
			}
			printf("-%s\n", tb.rd);
		}
		/*
		id = fork();
		if (id == 0)
		{
			rl_clear_history();
			free(s);
			exit(0);
		}
		else
			waitpid(-1, NULL, 0);
		*/free(tb.rd);
	}
}

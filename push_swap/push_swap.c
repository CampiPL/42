/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:35:24 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/19 11:59:29 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	while (i >= 0)
		free(args[i--]);
	free(args);
}

static void	init_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	if (argc == 2)
		ft_free_args(args);
	index_stack(stack_a);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*temp;
	t_list	*next;

	temp = *stack_a;
	next = temp->next;
	while (temp && next)
	{
		if (temp->content > next->content)
			return (0);
		temp = temp->next;
		next = next->next;
	}
	return (1);
}
/*
void	print_stack(t_list **stack, char *c)
{
	t_list	*temp;

	temp = *stack;
	ft_putendl_fd(c, 1);
	ft_putendl_fd("_", 1);
	while (temp)
	{
		ft_putnbr_fd(temp->content, 1);
		ft_putendl_fd("", 1);
		temp = temp->next;
	}
	ft_putendl_fd("_", 1);
}
*/

static void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		exit(0);
	check_argv(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

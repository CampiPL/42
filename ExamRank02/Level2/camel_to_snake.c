/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:44:21 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/16 13:01:05 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	int		upper;
	int		total;
	char	*string;

	if (argc == 2)
	{
		i = 0;
		upper = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				upper++;
			i++;
		}
		total = i + upper;
		string = (char *)malloc(sizeof(char) + total);
		i = 0;
		upper = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				string[i + upper] = '_';
				upper++;
				string[i + upper] = argv[1][i] + 32;
			}
			else
				string[i + upper] = argv[1][i];
			i++;
		}
		write(1, string, total);
	}
	write(1, "\n", 1);
	return (0);
}

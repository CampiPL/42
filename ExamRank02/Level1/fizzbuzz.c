/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:45:47 by jdepka            #+#    #+#             */
/*   Updated: 2024/04/16 10:01:08 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

int	main()
{
	char	num[3];
	int		temp;
	int		index;

	for (int i=1; i<=100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			temp = i;
			index = 0;
			while (temp != 0)
			{
				num[index] = (temp % 10) + 48;
				temp /= 10;
				index++;
			}
			index--;
			while (index >= 0)
			{
				write(1, &num[index], 1);
				index--;
			}
		}
		write(1, "\n", 1);
	}
	return (0);
}

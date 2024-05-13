/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:56:03 by jdepka            #+#    #+#             */
/*   Updated: 2024/05/13 13:59:12 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	c;
    char 	*buff = malloc(10000);

    while ((rd = read(fd, &c, 1)) > 0)
    {
        buff[i++] = c;
        if (c == '\n')
            break ;
    }
    if ((!buff[i - 1] && !rd) || rd == -1)
    {
        free(buff);
        return (NULL);
    }
    buff[i] =  '\0';
    return(buff);
}

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s ", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF", line);
		close(fd);
	}
	return (0);
}

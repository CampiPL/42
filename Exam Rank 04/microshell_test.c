/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:41:26 by jdepka            #+#    #+#             */
/*   Updated: 2024/07/24 17:52:25 by jdepka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	err(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot go to directory ")
			, err(argv[1]), err("\n"));
	return (0);
}

int	exec(char **argv, int i, char **envp)
{
	int	fd[2];
	int	status;
	int	has_pipe;
	int	pid;

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (!has_pipe && !strcmp(*argv, "cd"))
		return (cd(argv, i));
	if (has_pipe && pipe(fd) == -1)
		return (err("error: fatal\n"));
	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[0], 0) == -1
				|| close(fd[0]) == -1 || close(fd[1]) == -1))
			return (err("error: fatal\n"));
		if (!strcmp(*argv, "cd"))
			return (cd(argv, i));
		execve(*argv, argv, envp);
		return (err("error: cannot execute "), err(*argv), err("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[1], 1) == -1
			|| close(fd[0]) == -1 || close(fd[1]) == -1))
		return (err("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	status;

	if (argc > 1)
	{
		i = 0;
		status = 0;
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (i)
				exec(argv, i, envp);
		}
	}
	return (status);
}

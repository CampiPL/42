/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakhlou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:11:57 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/06/14 16:22:58 by rmakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/syscall.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <errno.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct t_cmd {
	char	*path;
	char	*cmd;
	char	*builin;
	char	*arg;
	char	*nin;
	char	*nout;
	int		in;
	int		out;
}	t_c;

typedef struct t_b {
	char	*rd;
	char	**env;
	char	**penv;
	int		lenv;
	int		pid;
	int		**pip;
	int		i;
	int		max;
	struct t_c	*cmd;
}	t_b;

char	*ft_strsimp(char *s);
int	ft_verifcote(char *s);
int	ft_verifpip(char *s);
void	ft_signal(void);
int	ft_verifwarg(char *s);
int     ft_verifredir(char *s);

#endif

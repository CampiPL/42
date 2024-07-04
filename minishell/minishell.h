/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:11:57 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/04 17:41:36 by jdepka           ###   ########.fr       */
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

typedef struct t_c {
	char	*path;
	char	**cmd;
	char	*builtin;
	char	*heredoc;
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
	int		err;
	int		hist;
	//int		pid;
	//int		**pip;
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
char	**ft_penv(char **env);
char    **ft_splitpip(char *s, char c);
char    *ft_convarg(char *s);
void    ft_prep(t_b *tb);
void	ft_clean(t_b *tb);
void	minishell(t_b *mini);

#endif

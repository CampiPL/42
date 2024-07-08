/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:11:57 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/08 20:34:22 by ubuntu           ###   ########.fr       */
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

# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7

typedef struct s_cmd {
	char			*str;
	int				type;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

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
void	mini(t_b *mini);

t_cmd	*get_start(char *rd);
int		next_alloc(char *line, int *i);
void	type_arg(t_cmd *token);

#endif

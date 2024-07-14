/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdepka <jdepka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:11:57 by rmakhlou          #+#    #+#             */
/*   Updated: 2024/07/14 17:03:36 by jdepka           ###   ########.fr       */
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

typedef struct t_c
{
	char		*path;
	char		**cmd;
	char		*builtin;
	char		*heredoc;
	char		*nin;
	char		*nout;
	int			in;
	int			out;
	struct t_b	*orig;
}	t_c;

typedef struct t_b
{
	char		*rd;
	char		**env;
	char		**secret_env;
	char		**penv;
	int			lenv;
	int			err;
	int			hist;
	int			pipin;
	int			pipout;
	int			fdin;
	int			fdout;
	int			in;
	int			out;
	int			parent;
	int			exec;
	int			i;
	int			max;
	struct t_c	*cmd;
}	t_b;

# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define HEREDOC 7

# define BUFF_SIZE 4096

typedef struct s_cmd
{
	char			*str;
	int				type;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_sig;

char	*ft_strsimp(char *s);
int		ft_verifcote(char *s);
int		ft_verifpip(char *s);
void	ft_signal(void);
int		ft_verifwarg(char *s);
int		ft_verifredir(char *s);
char	**ft_penv(char **env);
char	**ft_splitpip(char *s, char c);
char	*ft_convarg(char *s);
void	ft_prep(t_b *tb);
void	ft_clean(t_b *tb);
void	mini(t_b *mini);
char	*ft_geterrno(void);
void	ft_seterrno(int err);
char	**envcpy(char **env);
char	*ft_path(char *cmd, char **env);

void	ft_unset(char **args, t_b *mini);
int		next_alloc(char *line, int *i);
void	type_arg(t_cmd *cmd);
int		is_type(t_cmd *cmd, int type);
int		is_types(t_cmd *cmd, char *types);
t_cmd	*next_run(t_cmd *cmd);
void	redir_and_exec(t_b *mini, t_cmd *cmd);
void	*ft_memdel(void *ptr);
void	free_cmd(t_cmd *start);
void	exec_cmd(t_b *mini, t_cmd *cmd);
void	free_cmdarg(char **cmdarg);
void	exec_bin(char **cmdarg, t_b *mini);
void	sig_init(void);
void	ft_close(int fd);
void	close_fds(t_b *mini);
void	reset_fds(t_b *mini);
void	reset_std(t_b *mini);
int		is_builtin(char *command);
void	exec_builtin(char **args, t_b *mini);
void	ft_echo(char **args);
void	ft_pwd(void);
void	ft_env(char **env);
void	ft_cd(char **args, char **env);
int		is_in_env(char **env, char *args);
void	env_add(char *value, char ***env);
void	ft_export(char **args, t_b *mini);
void	print_sorted_env(char **env);
int		str_env_len(char **env);
void	sort_env(char **tb, int env_len);
int		is_valid_env(const char *env);
void	redir(t_b *mini, t_cmd *cmd, int type);
void	input(t_b *mini, t_cmd *cmd);
void	heredoc(t_b *mini, t_cmd *cmd);

extern t_sig	g_sig;

#endif

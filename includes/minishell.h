/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:00 by dbessa            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/05/10 14:18:30 by dbessa           ###   ########.fr       */
=======
/*   Updated: 2024/05/10 18:27:05 by dbessa           ###   ########.fr       */
>>>>>>> 40c61ad (test: trying more things to add pipes)
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include "../libft/includes/libft.h"

typedef struct s_word
{
	char			*word;
	unsigned int	flag;
	int				fd_in;
	int				fd_out;
	int				ret;
	pid_t			pid;
	struct s_word	*head;
	struct s_list	*env;
	struct s_word	*next;
}	t_word;

typedef struct s_data
{
	t_list			*env;
	char			**envp;
	char			*pwd;
	char			*raw_cmd;
	struct s_word	*prompt;
}	t_data;

enum e_token
{
	MS_WORD = 1,
	MS_PIPE = 2,
	MS_REDIRECT_IN = 4,
	MS_REDIRECT_OUT = 8,
	MS_REDIRECT_FILE = 16,
	MS_APPEND = 32,
	MS_HEREDOC = 64,
};

enum e_builtins
{
	MS_ECHO = 256,
	MS_CD = 512,
	MS_PWD = 1024,
	MS_EXPORT = 2048,
	MS_UNSET = 4096,
	MS_ENV = 8192,
	MS_EXIT = 16384,
};

int				quote_number(t_data *data);
int				exec_command(t_data *data);
int				many_char(char *s, char c);
int				is_builtin(t_data *data);
int				func_pwd(void);
int				func_cd(t_word *prompt);
int				func_echo(t_word *prompt);
int				func_env(t_list *env);
int				func_export(t_word *prompt, t_list *env);
int				func_unset(t_word *prompt, t_list **env);

void			func_exit(t_data *data);
void			print_env(void);
void			handle_prompt(t_data *data);
void			free_matrix(char **arguments);
void			free_all(char **arguments, char *prompt);
void			mini_clear(void);
void			sigint_handle(int signal);
void			set_sighandle(void);
void			quote_error(void);
void			expand_prompt(t_word **prompt);

char			*shell_name(t_list *env);
char			**transform_list(t_word **prompt1);

t_list			*get_env_lst(void);

t_word			*tokenizer(t_data *data);
unsigned int	give_token(char *word, int last_flag);
void			print_word(t_word **prompt);
void			free_prompt(t_word *prompt);
t_word			*ms_lstnew(void *word);
void			ms_lstadd_back(t_word **lst, t_word *new);
t_list			*ms_create_env_lst(void);
t_word			*ms_create_word_lst(char *line, t_list *env_lst);
int				get_word_len(char *line);
int				ms_ismeta(char *c);
int				ms_find_next_quotes(char *line);
void			tokenize_prompt(t_word **prompt);
int				pipe_operator (t_data *data);
char			*use_path(char *arg, t_list *env);
char			**env_to_matrix(t_list *env);
int				ms_pipe(t_word *node);
void			ms_exec_pipe(t_word *node, t_list **env_lst);
void			ms_bin_exec_pipe(t_word *node, t_list *env_lst);
void			ms_close_pipe(int *fd);
void			ms_close_all_fd(t_word *node);
void			exec_all_commands(t_data *data);

#endif

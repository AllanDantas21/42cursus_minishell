/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:49:46 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:52:31 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

unsigned int	give_token(char *word, int last_flag);
void			remove_quotes_all_prompt(t_word *prompt);
char			*remove_quotes2(char *line);
int				parse_quotes(t_data *data);
int				syntax_errors(t_data *data);
int				check_pipe_syntax(t_data *data);
int				check_redir_syntax(t_data *data);
int				quote_number(t_data *data);
int				is_all_space(char *line);
int				executor(t_data *data);
int				ft_pipe(t_word *prompt);
int				do_redir(t_word *prompt);
int				redir_in(t_word *prompt);
int				redir_out(t_word *prompt);
int				append(t_word *prompt);
int				heredoc(t_word *prompt);
int				parse_prompt(t_data *data);
int				exec_command(t_data *data);
int				many_char(char *s, char c);
int				is_builtin(t_data *data);
int				func_pwd(t_word *prompt);
int				func_cd(t_word *prompt);
int				func_echo(t_word *prompt);
int				func_env(t_list *env, t_word *prompt);
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
char			**transform_list(t_word *prompt);
void			print_word(t_word **prompt);
void			free_prompt(t_word *prompt);
void			lstadd_back(t_word **lst, t_word *new);
void			tokenize_prompt(t_word **prompt);
char			*use_path(char *arg, t_list *env);
char			**env_to_matrix(t_list *env);
void			redirect_stdio(t_word *prompt);
void			close_sentence_fd(t_word *prompt);
void			bin_exec_pipe(t_word *prompt);
void			close_fds(t_word *prompt);
void			exec_pipe(t_word *prompt);
void			wait_cmds(t_word *node);
void			close_pipe(int *fd);
t_list			*get_env_lst(void);
t_list			*create_env_lst(void);
t_word			*lstnew(void *word);
t_word			*get_last_word(t_word *prompt);
t_word			*tokenizer(t_data *data);
t_word			*create_word_lst(char *line, t_list *env_lst);
t_word			*next_command_pipe(t_word *prompt);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:50:30 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:58:12 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_word
{
	char			*word;
	int				fd_in;
	int				fd_out;
	int				status;
	pid_t			pid;
	unsigned int	flag;
	struct s_word	*head;
	struct s_list	*env;
	struct s_word	*next;
}	t_word;

typedef struct s_data
{
	t_list			*env;
	int				status;
	char			**envp;
	char			*pwd;
	char			*raw_cmd;
	struct s_word	*prompt;
}	t_data;

enum e_token
{
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_FILE,
	APPEND,
	HEREDOC,
};

#endif
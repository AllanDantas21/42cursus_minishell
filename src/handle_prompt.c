/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/10 14:00:12 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_prompt(t_data *data)
{
	add_history(data->raw_cmd);
	if (!quote_number(data))
		return (quote_error());
	data->prompt = ms_create_word_lst(data->raw_cmd, data->env);
	tokenize_prompt(&data->prompt);
	expand_prompt(&data->prompt);
	if (ft_strchr_int(data->raw_cmd, '|') == 1)
		pipe_operator(data);
	else if (!is_builtin(data))
		exec_command(data);
	print_word(&data->prompt);
	free_prompt(data->prompt);
}

void	tokenize_prompt(t_word	**prompt)
{
	t_word	*token;
	int		last_flag;

	token = (*prompt)->head;
	last_flag = token->flag;
	while (token)
	{
		token->flag = give_token(token->word, last_flag);
		last_flag = token->flag;
		token = token->next;
	}
}

unsigned int	give_token(char *word, int last_flag)
{
	if (!word)
		return (-1);
	if (!ft_strncmp("|", word, 2))
		return (MS_PIPE);
	else if (!ft_strncmp("<", word, 2))
		return (MS_REDIRECT_IN);
	else if (!ft_strncmp(">", word, 2))
		return (MS_REDIRECT_OUT);
	else if (!ft_strncmp(">>", word, 3))
		return (MS_APPEND);
	else if (!ft_strncmp("<<", word, 3))
		return (MS_HEREDOC);
	else if (last_flag == MS_REDIRECT_OUT || last_flag == MS_REDIRECT_IN
		|| last_flag == MS_HEREDOC || last_flag == MS_APPEND)
		return (MS_REDIRECT_FILE);
	return (MS_WORD);
}

void	print_word(t_word **prompt)
{
	t_word	*print;

	print = *prompt;
	while (print != NULL)
	{
		printf("WORD = %s\nTOKEN = %d\n", print->word, print->flag);
		print = print->next;
	}
}

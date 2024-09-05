/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:23:54 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:53:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redir_syntax(t_data *data)
{
	t_word	*prompt;

	prompt = data->prompt;
	if ((prompt->flag == REDIRECT_IN || prompt->flag == REDIRECT_OUT
			|| prompt->flag == APPEND))
	{
		ft_putstr_fd("minishell:  syntax error\n", 2);
		return (1);
	}
	prompt = get_last_word(prompt);
	if (prompt->flag == REDIRECT_IN || prompt->flag == REDIRECT_OUT
		|| prompt->flag == APPEND || prompt->flag == HEREDOC)
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	return (0);
}

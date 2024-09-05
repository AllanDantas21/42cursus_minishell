/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:52:48 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:53:48 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_out(t_word *prompt)
{
	t_word	*head;
	int		fd_out;

	head = prompt;
	while (head && head->flag != WORD)
		head = head->next;
	while (prompt && prompt->flag != PIPE)
	{
		if (prompt->flag == REDIRECT_OUT)
		{
			fd_out = open(prompt->next->word, O_WRONLY
					| O_CREAT | O_TRUNC, 0644);
			if (fd_out == (-1))
			{
				perror("open");
				return (-1);
			}
			head->fd_out = fd_out;
		}
		prompt = prompt->next;
	}
	return (0);
}

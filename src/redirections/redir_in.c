/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:53:55 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:53:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redir_in_loop(t_word *prompt, t_word *head, int fd_in)
{
	while (prompt && prompt->flag != PIPE)
	{
		if (prompt->flag == REDIRECT_IN)
		{
			if (access(prompt->next->word, F_OK | R_OK) != -1)
			{
				fd_in = open(prompt->next->word, O_RDONLY);
				if (fd_in == (-1))
				{
					perror("open");
					return (-1);
				}
				head->fd_in = fd_in;
			}
			else
			{
				printf("Error: No such file as '%s'\n", prompt->next->word);
				return (-1);
			}
		}
		else if (prompt->flag == HEREDOC)
			head->fd_in = heredoc(prompt);
		prompt = prompt->next;
	}
	return (0);
}

int	redir_in(t_word *prompt)
{
	t_word	*head;
	int		fd_in;

	fd_in = -1;
	head = prompt;
	while (head && head->flag != WORD)
		head = head->next;
	if (redir_in_loop(prompt, head, fd_in) == -1)
		return (-1);
	return (0);
}

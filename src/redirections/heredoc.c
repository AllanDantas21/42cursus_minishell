/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:46:57 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:53:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_loop(char *line, t_word *prompt, int *fd)
{
	while (42)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(prompt->next->word, line, ft_strlen(line) + 1))
			break ;
		else if (line)
		{
			write (fd[1], line, ft_strlen(line));
			write (fd[1], "\n", 1);
			free(line);
		}
	}
	if (line)
		free(line);
}

int	heredoc(t_word *prompt)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		return (-1);
	line = NULL;
	heredoc_loop(line, prompt, fd);
	close (fd[1]);
	return (fd[0]);
}

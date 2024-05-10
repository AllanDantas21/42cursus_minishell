/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:17:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/10 13:15:39:45dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command_pipe(t_word *prompt, int fd_aux, int *fd)
{
	char	**envp;
	char	**single_cmd;

	dup2(fd_aux, STDIN_FILENO);
	printf("OIE\n");
	if (prompt->next->word != NULL)
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	if (prompt->flag == MS_PIPE)
		prompt = prompt->next;
	prompt->word = use_path(prompt->word, prompt->env);
	envp = env_to_matrix(prompt->env);
	single_cmd = transform_list(&prompt);
	if ((execve(prompt->word, single_cmd, envp)) == -1)
	{
		perror("Error executing command");
		exit(EXIT_SUCCESS);
	}
	free_matrix(single_cmd);
	free_matrix(envp);
	return (0);
}

int	pipe_operator (t_data *data)
{
	int		pid;
	int		fd[2];
	int		fd_aux;
	t_word	*prompt;

	prompt = data->prompt->head;
	fd_aux = 0;
	while (prompt)
	{
		if (pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == 0 && prompt->flag != MS_PIPE)
			execute_command_pipe(prompt, fd_aux, fd);
		wait(NULL);
		close(fd[1]);
		fd_aux = fd[0];
		prompt = prompt->next;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:04:51 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 22:05:17 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_sighandle(void)
{
	struct sigaction	sig;

	signal(SIGQUIT, SIG_IGN);
	sig.sa_handler = sigint_handle;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGINT);
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	return ;
}

void	sigint_handle(int signal)
{
	extern unsigned int	g_exit_status;

	if (signal == SIGINT)
	{
		if (RL_ISSTATE(RL_STATE_READCMD))
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
		else
			write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		g_exit_status = 130;
	}
	return ;
}

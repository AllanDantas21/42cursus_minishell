/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/09/04 22:04:24 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	t_data	data;

	data.env = get_env_lst();
	set_sighandle();
	while (42)
	{
		data.pwd = shell_name(data.env);
		data.raw_cmd = readline(data.pwd);
		if (data.raw_cmd == NULL || *data.raw_cmd == EOF)
			func_exit(&data);
		if (data.raw_cmd && *data.raw_cmd)
			handle_prompt(&data);
		free(data.raw_cmd);
		free(data.pwd);
	}
	ft_lstclear(&data.env, free);
	return (0);
}

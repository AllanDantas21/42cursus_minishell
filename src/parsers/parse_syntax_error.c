/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:45:26 by aldantas          #+#    #+#             */
/*   Updated: 2024/09/04 21:53:53 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_errors(t_data *data)
{
	if (check_pipe_syntax(data) || check_redir_syntax(data))
		return (1);
	return (0);
}

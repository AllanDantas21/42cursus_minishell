/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:34:11 by dwbessa           #+#    #+#             */
/*   Updated: 2024/09/04 21:53:46 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*lstnew(void *word)
{
	t_word	*new;

	new = (t_word *)malloc(sizeof(t_word));
	if (!new)
		return (NULL);
	new->word = word;
	new->flag = 0;
	new->pid = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->status = -1;
	new->next = NULL;
	new->env = NULL;
	new->head = NULL;
	return (new);
}

void	lstadd_back(t_word **lst, t_word *new)
{
	t_word	*last_node;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
	return ;
}

t_list	*create_env_lst(void)
{
	extern char	**environ;
	t_list		*head;
	t_list		*node;
	int			i;

	i = 0;
	head = NULL;
	while (environ[i])
	{
		node = ft_lstnew(ft_strdup(environ[i]));
		if (!node)
		{
			ft_lstclear(&node, free);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

char	**transform_list(t_word *prompt)
{
	t_word				*aux;
	char				**mat;
	unsigned int		mat_positions;
	unsigned int		i;

	if (!prompt)
		return (NULL);
	aux = prompt;
	i = -1;
	mat_positions = 0;
	while (aux && aux->flag == WORD)
	{
		aux = aux->next;
		mat_positions++;
	}
	mat = ft_calloc(mat_positions + 1, sizeof(char *));
	if (!mat)
		return (NULL);
	while (++i < mat_positions)
	{
		mat[i] = ft_strdup(prompt->word);
		prompt = prompt->next;
	}
	return (mat);
}

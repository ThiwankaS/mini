/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:37:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 20:57:57 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_list	*list_add_back(t_list *list, char *str);
char *get_token(char *input, int *index);
int ft_isspecial(int c);

int	extract_tokens(t_list **tokens, char *input)
{
	int		i;
	char *token;

	i = 0;
	token = NULL;
	while(input && input[i] && ft_isspace(input[i]))
		i++;
	while (input && input[i])
	{
		if (!ft_isspace(input[i]))
		{
			token = get_token(input, &i);
			*tokens = list_add_back(*tokens, token);
		}
		i++;
	}
	return (0);
}

char *get_token(char *input, int *index)
{
	int i;
	int start;
	char *token;

	i = *index;
	start = *index;
	token = NULL;
	while (input && input[i])
	{
		if (ft_isspecial(input[i]) && !ft_isquoted(input, i))
		{
			token = ft_strnmdup(input, start, i);
			break;
		}
		i++;
	}
	if (input[i] == '\0' && token == NULL)
		token = ft_strnmdup(input, start, i);
	*index = i;
	return (token);
}

t_list	*list_add_back(t_list *list, char *str)
{
	t_list	*node;
	t_list	*current;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->token = ft_strdup(str);
	if (!list)
		return (node);
	current = list;
	while (current && current->next)
		current = current->next;
	current->next = node;
	return (list);
}

t_cmd	*list_add_command(t_cmd *cmds, t_cmd *node)
{
	t_cmd	*current;

	if (!node)
		return (cmds);
	if (!cmds)
		return (node);
	current = cmds;
	while (current && current->next)
		current = current->next;
	current->next = node;
	return (cmds);
}

int ft_isspecial(int c)
{
	if(c == '|')
		return (1);
	return (0);
}

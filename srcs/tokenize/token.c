/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:37:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 16:02:49 by tsomacha         ###   ########.fr       */
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
	while (input && input[i])
	{
		token = get_token(input, &i);
		*tokens = list_add_back(*tokens, ft_strtrim(token, ISSPACE));
		i++;
	}
	return (0);
}

char *get_token(char *input, int *index)
{
	int i = *index, start;
	char quote_char = '\0';

	while (input[i] && (ft_isspecial(input[i]) || ft_isspace(input[i])))
		i++;
	start = i;
	while (input[i])
	{
		if (ft_isquote(input[i]))
		{
			if (!quote_char)
				quote_char = input[i];
			else if (quote_char == input[i])
				quote_char = '\0';
			i++;
		}
		else if (!quote_char && ft_isspecial(input[i]))
			break;
		else
			i++;
		while (!quote_char && ft_isspace(input[i]) && ft_isquote(input[i + 1]))
			i++;
	}
	*index = i;
	return ft_strnmdup(input, start, i);
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

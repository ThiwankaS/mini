/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:15 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 14:16:26 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_cmd *handel_simpel(t_shell *mini, t_list *current)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
			return (NULL);
	cmd->type = set_command_type(current->token);
	cmd->cmd = get_command(current->token);
	cmd->command = set_path_name(mini, current->token);
	cmd->filename = ft_strdup("");
	cmd->num_args = get_num_args(current->token);
	cmd->args = set_arg_array(current->token, cmd->num_args);
	cmd->next = NULL;
	return (cmd);
}

char *get_command(char *token)
{
	char	*cmd;
	int		i;

	i = 0;
	cmd = NULL;
	if (!token)
		return (cmd);
	cmd = ft_extract_word(token, &i);
	return (cmd);
}

int get_num_args(char *token)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (token[i])
	{
		while (ft_isspace(token[i]))
			i++;
		if (token[i] == '\0')
			break ;
		count++;
		if (ft_isquote(token[i]))
			ft_skip_quoted(token, &i);
		else
		{
			while (token[i] && !ft_isspace(token[i]) && !ft_isquote(token[i]))
				i++;
		}
	}
	return (count);
}

char	*ft_extract_word(char *token, int *index)
{
	int		i;
	int		start;
	char	*word;
	char	quote_char;

	i = *index;
	while (ft_isspace(token[i]))
		i++;
	start = i;
	if (ft_isquote(token[i]))
	{
		quote_char = token[i++];
		start = i;
		while (token[i] && token[i] != quote_char)
			i++;
		word = ft_strnmdup(token, start, i);
		if (token[i] == quote_char)
			i++;
	}
	else
	{
		while (token[i] && !ft_isspace(token[i]) && !ft_isquote(token[i]))
			i++;
		word = ft_strnmdup(token, start, i);
	}
	*index = i;
	return (word);
}


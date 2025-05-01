/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:23:15 by tsomacha          #+#    #+#             */
/*   Updated: 2025/05/01 07:39:31 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_cmd *handel_simpel(t_shell *mini, t_list *current)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
			return (NULL);
	init_cmd(cmd);
	cmd->type = set_command_type(current->token);
	cmd->cmd = get_command(current->token);
	cmd->command = set_path(mini, current->token);
	cmd->filename = ft_strdup("");
	cmd->num_args = get_num_args(current->token);
	cmd->args = set_arg_array(current->token, cmd->num_args);
	cmd->next = NULL;
	return (cmd);
}

char *get_command(char *token)
{
	int		i;
	int		start;
	char	*cmd;
	char	quote_char;

	i = 0;
	cmd = NULL;
	while (token && ft_isspace(token[i]))
		i++;
	start = i;
	if (token && ft_isquote(token[i]))
	{
		quote_char = token[i];
		while (token && token[i] && token[i] != quote_char)
			i++;
		cmd = ft_strnmdup(token, start + 1, i - 1);
	}
	else
	{
		while (token && token[i] && !ft_isspace(token[i]))
			i++;
		cmd = ft_strnmdup(token, start, i);
	}
	return (cmd);
}

int get_num_args(char *token)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (token[i])
	{
		while (ft_isspace(token[i]))
			i++;
		if (token[i] == '\0')
			break ;
		if (!ft_isquoted(token, i))
			count++;
		while (token[i] && !ft_isspace(token[i]))
			i++;
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
	word = NULL;
	while (token[i] && ft_isspace(token[i]))
		i++;
	start = i;
	if (ft_isquote(token[i]))
	{
		quote_char = token[i];
		while (token[i] && token[i] != quote_char)
			i++;
		word = ft_strnmdup(token, start + 1, i - 1);
	}
	else
	{
		while (token[i] && !ft_isspace(token[i]))
			i++;
		word = ft_strnmdup(token, start, i);
	}
	*index = i;
	return (word);
}

void init_cmd(t_cmd *cmd)
{
	cmd->type = 0;
	cmd->cmd = NULL;
	cmd->command = NULL;
	cmd->filename = NULL;
	cmd->num_args = 0;
	cmd->args = NULL;
	cmd->next = NULL;
}


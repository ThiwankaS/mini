/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:01:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/26 02:35:42 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_cmd *handle_quoted(t_shell *mini, char *token)
{
	t_cmd *cmd = malloc(sizeof(t_cmd));
	if(!cmd)
		return (NULL);
	cmd->cmd = get_command(token);
	cmd->type = SMPL_CMD;
	cmd->command = set_path_name(mini, token);
	cmd->num_args = 2;
	cmd->filename = NULL;
	cmd->args = set_arg_array(token, cmd->num_args);
	cmd->next = NULL;
	return (cmd);
}

char *enclosed_in_quotes(char *input)
{
	char *str = NULL;
	int len = ft_strlen(input);

	str = ft_strnstr(input, "'", len);
	if(str)
		return (str);
	str = ft_strnstr(input, "\"", len);
	if(str)
		return (str);
	return (str);
}

int check_if_quoted(char *input)
{
	int len = ft_strlen(input);

	if(len == 0)
		return (0);
	else if(input[0] == '\'' && input[len-1] == '\'')
		return (1);
	else if(input[0] == '"' && input[len-1] == '"')
		return (1);
	else
		return (0);
}

char *remove_quotes(char *str)
{
	int len = ft_strlen(str);
	char *res = ft_strnmdup(str, 1, len - 1);
	return (res);
}

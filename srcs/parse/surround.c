/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surround.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 04:06:53 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 17:16:54 by tsomacha         ###   ########.fr       */
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
	cmd->command = set_path(mini, token);
	cmd->num_args = 2;
	cmd->filename = NULL;
	cmd->args = set_arg_array(token, cmd->num_args);
	cmd->next = NULL;
	return (cmd);
}

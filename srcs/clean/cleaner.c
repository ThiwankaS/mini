/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:48:20 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 14:43:25 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	clear_commands(t_shell *mini);
int	clear_tokens(t_shell *mini);
int	clear_array(char **array);

void print_cmd(t_cmd *cmd)
{
	int i = 0;
	printf("type : %d\n", cmd->type);
	printf("nums : %d\n", cmd->num_args);
	printf("cmd : %s\n", cmd->cmd);
	printf("command : %s\n", cmd->command);
	printf("args : - \n");
	while(cmd->args[i])
	{
		printf("args[%d] : %s\n", i, cmd->args[i]);
		i++;
	}
	printf("filename : %s\n", cmd->filename);
}

int	clear_and_exit(t_shell *mini)
{
	clear_commands(mini);
	clear_tokens(mini);
	mini->num_cmds = 0;
	return (0);
}

int	clear_commands(t_shell *mini)
{
	t_cmd	*current;
	t_cmd	*temp;

	current = mini->cmds;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp->command)
			free(temp->command);
		if (temp->cmd)
			free(temp->cmd);
		if (temp->filename)
			free(temp->filename);
		if (temp->args)
			clear_array(temp->args);
		free(temp);
	}
	mini->cmds = NULL;
	return (0);
}

int	clear_tokens(t_shell *mini)
{
	t_list	*current;
	t_list	*temp;

	current = mini->tokens;
	while (current)
	{
		temp = current;
		current = current->next;
		if (temp->next)
			free(temp->token);
		free(temp);
	}
	mini->tokens = NULL;
	return (0);
}

int	clear_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	if (array)
		free(array);
	return (0);
}

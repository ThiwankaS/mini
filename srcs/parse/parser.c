/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:00:03 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 16:53:07 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void expand(t_shell *mini, t_list *list);

int parse_and_expand(t_shell *mini)
{
	expand(mini, mini->tokens);
	if (mini->cmds->cmd)
	{
		if(!mini->cmds->command || builtin_cmd(mini->cmds->cmd))
		{
			if (check_builtin(mini) == 2)
				return (2);
			else
				return (1);
		}
	}
	return (0);
}

static void expand(t_shell *mini, t_list *list)
{
	t_list	*current;
	t_cmd	*cmd;

	current = list;
	cmd = NULL;
	while (current)
	{
		if (enclosed_in_quotes(current->token))
			cmd = handle_quoted(mini, current->token);
		else if (ft_strchr(current->token, '$'))
			cmd = handle_dollar(current, mini);
		else if (ft_strchr(current->token, '>'))
			cmd = handel_output(mini, current->token);
		else if (ft_strchr(current->token, '<'))
			cmd = handel_input(mini, current->token);
		else
			cmd = handel_simpel(mini, current);
		mini->cmds = list_add_command(mini->cmds, cmd);
		mini->num_cmds++;
		cmd = NULL;
		current = current->next;
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
char **set_arg_array(char *token, int size)
{
	int		i;
	int		step;
	char	**args;

	step = 0;
	i = 0;
	args = malloc((size + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	while (step < size && token[i])
	{
		args[step] = ft_extract_word(token, &i);
		step++;
	}
	args[step] = NULL;
	return (args);
}





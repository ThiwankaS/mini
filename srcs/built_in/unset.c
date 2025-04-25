/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:48:57 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/25 05:42:48 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	remove_env_nodes(t_shell *mini, char *unset)
{
	t_env	*current;
	t_env	*prev;

	current = mini->initenv->env;
	prev = NULL;
	if (!unset)
		return ;
	while (current)
	{
		if (ft_strncmp(current->name, unset, ft_strlen(unset)) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				mini->initenv->env = current->next;
			free(current->name);
			if (current->value)
				free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

int	builtin_unset(t_shell *mini, char **unset)
{
	int	i;

	i = 1;
	if (!unset)
		return (1);
	while (unset[i])
		remove_env_nodes(mini, unset[i++]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:22:27 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 09:10:39 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	activate_shell(t_shell *mini, char *input)
{
	int		status;

	status = 0;
	status = input_validate(&input);
	if (status)
		return (status);
	status = extract_tokens(&mini->tokens, input);
	if (status)
		return (status);
	status = parse_and_expand(mini);
	if (status)
		return (status);
	status = execute(mini);
	if (status)
		return (status);
	// status = clear_and_exit(mini);
	// if (status)
	// 	return (status);
	mini->status = status;
	return (status);
}

void	init_mini_shell(t_shell *mini, char **envp)
{
	t_initenv	*env;

	init_env(&env, envp);
	mini->envp = envp;
	mini->num_cmds = 0;
	mini->tokens = NULL;
	mini->cmds = NULL;
	mini->initenv = env;
	mini->trim = NULL;
	mini->status = 42;
}

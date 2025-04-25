/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:48:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/25 05:40:33 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	check_builtin(t_shell *mini)
{
	char	*cmd;

	cmd = mini->cmds->cmd;
	if (mini->cmds->cmd)
	{
		if (ft_strncmp("cd", cmd, sizeof(cmd)) == 0)
			return (builtin_cd(mini));
		if (ft_strncmp("env", cmd, sizeof(cmd)) == 0)
			return (builtin_env(mini));
		if (ft_strncmp("pwd", cmd, sizeof(cmd)) == 0)
			return (builtin_pwd());
		if (ft_strncmp("exit", cmd, sizeof(cmd)) == 0)
			return (builtin_exit(mini));
		if (ft_strncmp("unset", cmd, sizeof(cmd)) == 0)
			return (builtin_unset(mini, mini->cmds->args));
		else
			return (0);
	}
	return (0);
}

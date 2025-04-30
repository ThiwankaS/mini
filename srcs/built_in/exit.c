/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:48:30 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 09:07:50 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	builtin_exit(t_shell *mini)
{
	if (isatty(STDIN_FILENO))
		printf("exit\n");
	clear_and_exit(mini);
	exit (mini->status);
}

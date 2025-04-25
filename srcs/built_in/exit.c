/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:48:30 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/25 05:30:12 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	builtin_exit(t_shell *mini)
{
	printf("exit\n");
	clear_and_exit(mini);
	exit (mini->status);
}

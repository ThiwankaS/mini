/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:00:35 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 03:26:54 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	handle_int(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_quit(int sig)
{
	if (sig == SIGQUIT)
	{
		(void)sig;
	}
}

void	init_sig(void)
{
	signal(SIGINT, handle_int);
	signal(SIGQUIT, handle_int);
}

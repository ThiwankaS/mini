/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:40:50 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/26 02:35:57 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

volatile sig_atomic_t	g_sig = 0;

void	init_env(t_initenv **initenv, char **envp)
{
	*initenv = malloc(sizeof(t_initenv));
	(*initenv)->copy_env = NULL;
	(*initenv)->env = NULL;
	list_env(&(*initenv)->env, envp);
}

int	main(int ac, char **av, char **envp)
{
	char		*input;
	int			status;
	t_initenv	*initenv;

	initenv = NULL;
	status = 0;
	(void)av;
	if (ac == 1)
	{
		init_sig();
		init_env(&initenv, envp);
		while (1)
		{
			input = readline(isatty(STDIN_FILENO) ? "minishell> " : NULL);
			if (!input)
			{
				if (isatty(STDIN_FILENO))
					write(STDIN_FILENO, "exit", 5);
				break;
			}
			if (ft_isempty(input))
			{
				free(input);
				continue ;
			}
			add_history(input);
			status = activate_shell(input, initenv);
			free(input);
		}
	}
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:40:50 by tsomacha          #+#    #+#             */
/*   Updated: 2025/05/01 22:36:29 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

volatile sig_atomic_t	g_sig = 0;

static int	ft_stealth_mode(t_shell	*mini);
static int	ft_interactive_mode(t_shell	*mini);

int	main(int ac, char **av, char **envp)
{
	int		status;
	t_shell	*mini;

	status = 1;
	mini = malloc(sizeof(t_shell));
	if (!mini)
		return (1);
	(void)av;
	if (ac == 1)
	{
		init_sig();
		init_mini_shell(mini, envp);
		if (isatty(STDIN_FILENO))
		{
			status = ft_interactive_mode(mini);
		}
		else
		{
			status = ft_stealth_mode(mini);
		}
	}
	return (status);
}

static int	ft_stealth_mode(t_shell	*mini)
{
	char	*input;
	int		status;

	while (true)
	{
		input = readline(NULL);
		if (!input)
		{
			clear_and_exit(mini);
			free(input);
			break ;
		}
		if (ft_isempty(input))
		{
			free(input);
			continue ;
		}
		status = activate_shell(mini, input);
		if (input)
			free(input);
	}
	return (status);
}

static int	ft_interactive_mode(t_shell	*mini)
{
	char	*input;
	int		status;

	input = NULL;
	while (true)
	{
		input = readline("@so_thiwanka > ");
		if (!input)
		{
			if (mini)
			{
				clear_and_exit(mini);
				free(mini);
			}
			break ;
		}
		if (ft_isempty(input))
		{
			free(input);
			continue ;
		}
		add_history(input);
		status = activate_shell(mini, input);
		if (input)
			free(input);
	}
	return (status);
}

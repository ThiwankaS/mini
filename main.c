/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:40:50 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 13:43:53 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

volatile sig_atomic_t	g_sig = 0;

static int	ft_stealth_mode(t_shell	*mini, char **envp);
static int	ft_interactive_mode(t_shell	*mini, char **envp);

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
		if (isatty(STDIN_FILENO))
			status = ft_interactive_mode(mini, envp);
		else
			status = ft_stealth_mode(mini, envp);
	}
	return (status);
}

int	ft_stealth_mode(t_shell	*mini, char **envp)
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
		status = activate_shell(mini, input, envp);
		free(input);
	}
	return (status);
}

int	ft_interactive_mode(t_shell	*mini, char **envp)
{
	char	*input;
	int		status;

	while (true)
	{
		input = readline("@so_thiwanka > ");
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
		add_history(input);
		status = activate_shell(mini, input, envp);
		free(input);
	}
	return (status);
}

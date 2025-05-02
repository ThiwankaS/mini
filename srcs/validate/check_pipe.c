/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:50:18 by tsomacha          #+#    #+#             */
/*   Updated: 2025/05/02 01:44:24 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	is_at_the_beginin(char *input);
static int	consective_pipes(char *input);

int	check_pipe_character(char *input)
{
	if (is_at_the_beginin(input))
		return (1);
	if (consective_pipes(input))
		return (1);
	return (0);
}

static int	is_at_the_beginin(char *input)
{
	int		i;
	char	*trimmed;

	i = 0;
	if (!input)
		return (0);
	trimmed = ft_strtrim(input, ISSPACE);
	while (trimmed && ft_isspace(trimmed[i]))
		i++;
	if (trimmed[i] == '|')
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}

static int	consective_pipes(char *input)
{
	int	i;

	i = 0;
	while (input && input[i])
	{
		if (input[i] == '|' && !ft_isquoted(input, i))
		{
			i++;
			while (input && ft_isspace(input[i]))
				i++;
			if (input[i] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

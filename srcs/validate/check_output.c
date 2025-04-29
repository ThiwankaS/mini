/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:43:50 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 15:03:49 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int	check_output_character(char *input)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strtrim(input, ISSPACE);
	while (str && str[i])
	{
		if (str[i] == '>' && !ft_isquoted(input, i))
		{
			i++;
			if (input[i] == '>')
				i++;
			while (input && ft_isspace(input[i]))
				i++;
			if (input[i] == '<')
				return (1);
			if (input[i] == '>')
				return (1);
		}
		i++;
	}
	return (0);
}

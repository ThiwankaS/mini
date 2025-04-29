/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:35:14 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 19:03:57 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char *handle_dollar(t_shell *mini, char *token)
{
	int		i;
	int		start;
	char	*result;
	char	*key;
	char	*value;

	i = 0;
	result = NULL;
	while(token && token[i])
	{
		if (token[i] == '$' && !in_single_quotes(token, i))
		{
			if (!result)
				result = ft_strnmdup(token, 0, i);
			i++;
			start = i;
			while(ft_isalnum(token[i]))
				i++;
			key = ft_strnmdup(token, start, i - 1);
			value = ft_getenv(mini, key);
			result = ft_strjoin(result, value);
		}
		i++;
	}
	printf("token : %s\n", result);
	return (result);
}

bool in_single_quotes(const char *str, int index)
{
	int		i;
	bool	in_single;

	i = 0;
	in_single = false;
	while(str && str[i] && i != index)
	{
		if (str[i] == '\'')
			in_single = !in_single;
		i++;
	}
	return (in_single);
}

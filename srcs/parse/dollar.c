/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:35:14 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 10:33:01 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char	*string_build(char *s1, char *s2);
static char *set_value(t_shell *mini, char *token, int *index);

char *handle_dollar(t_shell *mini, char *token)
{
	int		i;
	char	*result;
	char	*value;

	i = 0;
	result = ft_strdup("");
	while(token && token[i])
	{
		if (token[i] == '$' && !in_single_quotes(token, i))
		{
			result = string_build(result, ft_strnmdup(token, 0, i));
			i++;
			value = set_value(mini, token, &i);
			result = string_build(result, value);
			token = token + i;
			i = 0;
		}
		else
			i++;
	}
	result = string_build(result, token);
	return (result);
}

bool in_single_quotes(const char *str, int index)
{
	int		i;
	bool	in_single;

	if (!str || index < 0)
		return (false);
	i = 0;
	in_single = false;
	while (str[i] && i < index)
	{
		if (str[i] == '\'')
			in_single = !in_single;
		i++;
	}
	return (in_single);
}

static char	*string_build(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

static char *set_value(t_shell *mini, char *token, int *index)
{
	int i;
	int start;
	char *key;
	char *value;

	start = *index;
	i = *index;
	if (token && token[i] == '?')
	{
		i++;
		value = ft_itoa(mini->status);
	}
	else
	{
		while (ft_isalnum(token[i]))
		i++;
		key = ft_strnmdup(token, start, i);
		value = ft_getenv(mini, key);
		free(key);
	}
	*index = i;
	return (value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:01:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 13:58:57 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char	*enclosed_in_quotes(char *input)
{
	int		len;
	char	*str;

	str = NULL;
	len = ft_strlen(input);
	str = ft_strnstr(input, "'", len);
	if (str)
		return (str);
	str = ft_strnstr(input, "\"", len);
	if (str)
		return (str);
	return (str);
}

char	*remove_quotes(char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = ft_strnmdup(str, 1, len - 1);
	return (res);
}

int	ft_isquote(int c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

int	ft_skip_quoted(char *token, int *index)
{
	int		i;
	char	quote_char;

	i = *index;
	quote_char = token[i++];
	while (token[i] && token[i] != quote_char)
		i++;
	if (token[i] == quote_char)
		i++;
	*index = i;
	return (1);
}

bool	ft_isquoted(const char *str, int n)
{
	bool	in_single;
	bool	in_double;
	int		i;

	in_single = false;
	in_double = false;
	i = 0;
	while (str && str[i] && i != n)
	{
		if (str[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (str[i] == '"' && !in_single)
			in_double = !in_double;
		i++;
	}
	return (in_single || in_double);
}

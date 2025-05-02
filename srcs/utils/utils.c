/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:01:27 by tsomacha          #+#    #+#             */
/*   Updated: 2025/05/02 00:51:26 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char	*ft_strnmdup(char const *src, int n, int m)
{
	int		i;
	char	*dest;

	i = 0;
	dest = NULL;
	if (!src || m == 0)
		return (dest);
	dest = malloc(sizeof(char) * ((m - n) + 1));
	if (!dest)
		return (NULL);
	while (src && src[i + n] && (i + n) < m)
	{
		dest[i] = src[i + n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strnmcpy(char **dest, char *src, int n, int m)
{
	int	i;

	i = 0;
	if (n >= m || !src || !dest)
		return (-1);
	*dest = malloc(sizeof(char) * (m - n + 1));
	if (!*dest)
		return (-1);
	while ((i + n) < m && src[i + n])
	{
		(*dest)[i] = src[i + n];
		i++;
	}
	(*dest)[i] = '\0';
	return (i);
}

void	print_args(char **args, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		printf("args[%d] : %s\n", i, args[i]);
		i++;
	}
}

void	print(t_list *list, char *msg)
{
	t_list	*current;

	printf("\n%s\n", msg);
	current = list;
	while (current)
	{
		printf("%s\n", current->token);
		current = current->next;
	}
	printf("------------------------------------\n");
}

int	ft_arraylen(char **envp)
{
	int	len;

	len = 0;
	while (envp && envp[len])
		len++;
	return (len);
}

int	ft_isempty(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v')
		return (1);
	else
		return (0);
}

int	quotes_checker(char *input, int len)
{
	int	in_quote;
	int	i;

	i = 0;
	in_quote = 0;
	while (input && input[i] && i < len)
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (in_quote == 0)
				in_quote = input[i];
			else if (in_quote == input[i])
				in_quote = 0;
		}
		i++;
	}
	return (in_quote);
}

bool	builtin_cmd(char *cmd)
{
	static char	*builtins[6];
	int			i;

	i = 0;
	builtins[0] = "exit";
	builtins[1] = "cd";
	builtins[2] = "env";
	builtins[3] = "pwd";
	builtins[4] = "unset";
	builtins[5] = NULL;
	while (builtins[i])
	{
		if (ft_strncmp(cmd, builtins[i], sizeof(cmd)) == 0)
			return (true);
		i++;
	}
	return (false);
}

int	ft_lst_len(t_env *env)
{
	t_env	*temp;
	int		len;

	len = 0;
	temp = env;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

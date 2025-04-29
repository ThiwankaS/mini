/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:35:14 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 16:46:05 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

t_cmd *handle_dollar(t_list *list, t_shell *mini)
{
	t_cmd *cmd = NULL;
    t_list *current;
    char 	*token;
    char 	*expanded_token;
    int 	i;
	int		j;
	int 	var_start;
	int 	var_len;
	char 	*var_value;
	int		k;

	current = list;
	token = current->token;
    expanded_token = malloc(strlen(token) + 1);
	i = 0;
	j = 0;
    if (!expanded_token)
        return (NULL);
    while (token[i]) {
        if (token[i] == '$') {
            i++;
	 	var_start = i;
        while (token[i] && (ft_isalnum(token[i]) || token[i] == '_'))
            i++;
        var_len = i - var_start;
        char var_name[var_len + 1];
        ft_strlcpy(var_name, token + var_start, var_len + 1);
		var_value = extract_env_value(mini->initenv, var_name);
		k = 0;
        while (var_value[k])
            expanded_token[j++] = var_value[k++];
        } else
            expanded_token[j++] = token[i++];
    }
    expanded_token[j] = '\0';
	free(current->token);
	expanded_token = ft_strtrim(expanded_token, " ");
	current->token = expanded_token;
	return (cmd);
}

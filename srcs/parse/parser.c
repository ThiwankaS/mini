/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:00:03 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 16:25:40 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void expand(t_shell *mini, t_list *list);
int get_num_args(char *token);
void get_args(char **args, char *token, int size);
char *get_command(char *token);
char *set_path_name(t_shell *mini, char *token);
char **set_arg_array(char *token, int size);

int parse_and_expand(t_shell *mini)
{
	expand(mini, mini->tokens);
	if (mini->cmds->cmd)
	{
		if(!mini->cmds->command || builtin_cmd(mini->cmds->cmd))
		{
			if (check_builtin(mini) == 2)
				return (2);
			else
				return (1);
		}
	}
	return (0);
}
void handle_dollar(t_list *list, t_shell *mini)
{
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
        return ;
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
}

void expand(t_shell *mini, t_list *list)
{
	t_list *current = list;
	t_cmd *cmd = NULL;

	while(current)
	{
		handle_dollar(current, mini);
		if(enclosed_in_quotes(current->token))
			cmd = handle_quoted(mini, current->token);
		else if(ft_strchr(current->token, '>'))
			cmd = handel_output(mini, current->token);
		else if(ft_strchr(current->token, '<'))
			cmd = handel_input(mini, current->token);
		else
			cmd = handel_simpel(mini, current);
		mini->cmds = list_add_command(mini->cmds, cmd);
		mini->num_cmds++;
		cmd = NULL;
		current = current->next;
	}
}

char **set_arg_array(char *token, int size)
{
	int		i;
	int		step;
	char	**args;

	step = 0;
	i = 0;
	args = malloc((size + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	while (step < size && token[i])
	{
		args[step] = ft_extract_word(token, &i);
		step++;
	}
	args[step] = NULL;
	return (args);
}

char *set_path_name(t_shell *mini, char *token)
{
	(void) mini;
	//char	**path_dirs;
	char	*command = get_command(token);
	char	*path = "/bin/";
	char 	*cmd = ft_strjoin(path, command);
	return (cmd);
	//int		i;

	// i = 0;
	// command = ft_substr(token, 0, ft_strchr(token, ' ') - token);
	// path = command;
	// if (access(path, X_OK) == 0)
	// 	return (path);
	// else
	// 	path = NULL;
	// char *path_value = extract_env_value(mini->initenv, "PATH");
	// if (!path_value)
	// {
    // 	if (!builtin_cmd(command))
    // 	    printf("%s: command not found\n", command);
   	// 	free(command);
   	// 	return (NULL);
	// }
	// path_dirs = ft_split(path_value, ':');
	// if (!path_dirs)
    // 	return (NULL);
	// while (path_dirs && path_dirs[i])
	// {
	// 	path = ft_strjoin(path_dirs[i], "/");
	// 	path = ft_strjoin(path, command);
	// 	if (!path)
	// 		return (NULL);
	// 	if (access(path, X_OK) == 0)
	// 		return (path);
	// 	i++;
	// }
	// if (access(path, X_OK) == -1)
	// {
	// 	if (builtin_cmd(command))
	// 		return (NULL);
	// 	else
	// 		printf("%s: command not found1\n", command);
	// }
	// return (NULL);
}





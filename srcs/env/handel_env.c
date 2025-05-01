/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 05:37:36 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/30 21:44:21 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void	init_env(t_initenv **initenv, char **envp)
{
	*initenv = malloc(sizeof(t_initenv));
	(*initenv)->copy_env = NULL;
	(*initenv)->env = NULL;
	list_env(&(*initenv)->env, envp);
}

char *set_path(t_shell *mini, char *token)
{
	(void) mini;
	//char	*dir;
	char	*command = get_command(token);
	char	*path = "/bin/";
	char 	*cmd = ft_strjoin(path, command);
	//dir = getcwd(NULL, 0);
	//printf("path : %s\n", dir);
	return (cmd);

}
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

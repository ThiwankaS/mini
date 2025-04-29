/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:58:25 by tsomacha          #+#    #+#             */
/*   Updated: 2025/04/29 17:50:11 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void	updatewd(t_shell *mini, char *newpwd, char *oldpwd);
static int	home_error(char *msg);
static int	chdir_error(t_shell *mini);
static char	*handel_tilde(t_shell *mini, char *home);

int	builtin_cd(t_shell *mini)
{
	char	*home;
	char	*dir;
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	home = ft_getenv(mini, "HOME");
	dir = NULL;
	if (!home)
		return (home_error("cd: HOME not set\n"));
	if (!mini->cmds->args[1])
		dir = home;
	else
	{
		if ((ft_strncmp("~", mini->cmds->args[1], 1) == 0))
			dir = handel_tilde(mini, home);
		else
		{
			dir = ft_strjoin(getcwd(NULL, 0), "/");
			dir = ft_strjoin(dir, mini->cmds->args[1]);
		}
	}
	if (chdir(dir))
		return (chdir_error(mini));
	updatewd(mini, getcwd(NULL, 0), oldpwd);
	return (0);
}

static void	updatewd(t_shell *mini, char *newpwd, char *oldpwd)
{
	t_env	*env;

	env = mini->initenv->env;
	while (env)
	{
		if (ft_strncmp("PWD", env->name, 3) == 0)
		{
			free(env->value);
			env->value = ft_strdup(newpwd);
		}
		if (ft_strncmp("OLDPWD", env->name, 6) == 0)
		{
			free(env->value);
			env->value = ft_strdup(oldpwd);
		}
		env = env->next;
	}
}

static int	home_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

static char	*handel_tilde(t_shell *mini, char *home)
{
	char	*dir;

	dir = NULL;
	if (mini->cmds->args[1] && !mini->cmds->args[1][1])
		dir = home;
	else
		dir = ft_strjoin(home, ft_strchr(mini->cmds->args[1], '~') + 1);
	return (dir);
}

static int	chdir_error(t_shell *mini)
{
	printf("cd: %s: No such file or directory\n", mini->cmds->args[1]);
	return (1);
}

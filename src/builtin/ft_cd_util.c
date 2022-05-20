#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "parse.h"
#include "util.h"

void	print_error_cd(char *path)
{
	_putstr_fd("bash: cd: ", 2);
	_putstr_fd(path, 2);
	_putendl_fd(": No such file or directory", 2);
	g_minishell.state = 1;
}

void	change_global_oldpwd(char *prev)
{
	if (!g_minishell.oldpwd)
		g_minishell.oldpwd = strdup(prev);
	else
	{
		free(g_minishell.oldpwd);
		g_minishell.oldpwd = strdup(prev);
	}
}

void	change_envp_pwd(void)
{
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, "PWD"))
		{
			if (envp->value)
				free(envp->value);
			envp->value = strdup(getcwd(NULL, 256));
			break ;
		}
		envpl = envpl->next;
	}
}

void    change_envp_oldpwd(void)
{	
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, "OLDPWD"))
		{
			if (envp->value)
				free(envp->value);
			envp->value = strdup(g_minishell.oldpwd);
			break ;
		}
		envpl = envpl->next;
	}
}

void	change_values(char *now)
{
	change_global_oldpwd(now);
	change_envp_pwd();
	change_envp_oldpwd();
}

void	change_to_old_path(char *now)
{
	if (!g_minishell.oldpwd)
	{
		_putendl_fd("bash: cd: OLDPWD not set", 2);
		return ;
	}
	else
	{
		if (chdir(g_minishell.oldpwd))
		{
			_putstr_fd("bash: cd: ", 2);
			_putstr_fd(g_minishell.oldpwd, 2);
			_putendl_fd(": No such file or directory", 2);
			g_minishell.state = 1;
			return ;
		}
	}
	change_values(now);
}

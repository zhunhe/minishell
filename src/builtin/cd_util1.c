#include "../includehena/test.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern t_minishell g_minishell;

void    change_global_oldpwd(char **prev)
{
    if (!g_minishell.oldpwd)
        g_minishell.oldpwd = strdup(*prev);
    else
    {
        free(g_minishell.oldpwd);
        g_minishell.oldpwd = strdup(*prev);
    }
    free(*prev);
}

void    change_envp_pwd()
{
    t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!strcmp(envp->key, "PWD"))// TODO:: ft_strcmp
		{
            if (envp->value)
                free(envp->value);
			envp->value = strdup(getcwd(NULL, 256));
			break ;
		}
		envpl = envpl->next;
	}
}

void    change_envp_oldpwd()
{	
	t_list	*envpl;
	t_envp	*envp;

	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!strcmp(envp->key, "OLDPWD"))// TODO:: ft_strcmp
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
	change_global_oldpwd(&now);
	change_envp_pwd();
	change_envp_oldpwd();
}

void	change_to_old_path(char *now)
{
	if (!g_minishell.oldpwd)
	{
		write(2, "bash: cd: OLDPWD not set\n", 25);
		return ;
	}
	else
	{
		chdir(g_minishell.oldpwd);
	}
	change_values(now);
}
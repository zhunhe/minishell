#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"
#include "built_in.h"
#include "util.h"

#define TRUE 1
#define FALSE 0

char	*find_home_path(int *flag)
{
	t_list	*envpl;
	t_envp	*envp;
	char	*path;

	*flag = 0;
	path = NULL;
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (!_strcmp(envp->key, "HOME"))
		{
			path = envp->value;
			*flag = 1;
			break ;
		}
		envpl = envpl->next;
	}
	return (path);
}

void	using_environment_value(char *now)
{
	int		flag;
	char	*path;

	path = find_home_path(&flag);
	if (!flag)
	{
		_putendl_fd("bash: cd: HOME not set\n", 2);
		return ;
	}
	if (path == NULL || !_strcmp(path, ""))
		chdir(path);
	else
	{
		if (chdir(path) == -1)
			print_error_cd(path);
		else
			change_values(now);
	}
}

void	non_using_environment_value(char *now)
{
	chdir("/Users/juhur");
	change_values(now);
}

int	home_check(char *argv, char *now)
{
	if (!argv)
	{
		using_environment_value(now);
		return (TRUE);
	}
	else if (!_strncmp("~", argv, 1))
	{
		non_using_environment_value(now);
		return (TRUE);
	}
	free(now);
	return (FALSE);
}

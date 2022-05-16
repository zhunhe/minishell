/*
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"

extern t_minishell g_minishell;

static void	ft_print_env(char *key, char *value)
{
	write(1, key, strlen(key)); //TODO:: stlen
	write(1, "=", 1);
	write(1, value, strlen(value)); //TODO:: stlen
	write(1, "\n", 1);
}


void	ft_env(t_exec *data, int pipe_flag)
{
	t_list	*envpl;
	t_envp	*envp;
	char	**argv;

	argv = data->argv;
	argv++;
	if (*argv)
	{
		write(2, *argv, strlen(*argv));//TODO:: stlen
		write(2, "\n", 1);
		exit(1);
	}
	envpl = g_minishell.envp->next;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (envp->value)
			ft_print_env(envp->key, envp->value);
		envpl++;
	}
	g_minishell.state = 0;
	if (pipe_flag)
		exit(0);
}
*/

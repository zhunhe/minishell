#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "minishell.h"
#include "parse.h"

extern t_minishell g_minishell;

static void	ft_print_env(char *key, char *value)
{
	write(1, key, strlen(key)); //TODO:: strlen
	write(1, "=", 1);
	write(1, value, strlen(value)); //TODO:: strlen
	write(1, "\n", 1);
}


void	ft_env(t_exec *data, int pipe_flag)
{
	t_list	*envpl;
	t_envp	*envp;
	char	**argv;

	argv = data->cmd_argv;
	argv++;
	if (*argv)
	{
		write(2, "env must be one argv", 20);//TODO:: stlen
		write(2, "\n", 1);
		exit(1);
	}
	envpl = g_minishell.envp;
	while (envpl)
	{
		envp = (t_envp *)envpl->data;
		if (envp->value)
			ft_print_env(envp->key, envp->value);
		envpl = envpl->next;
	}
	g_minishell.state = 0;
	if (pipe_flag)
		exit(0);
}

#if 0

t_list *create_l()
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = 0;
	new->next = 0;
	return (new);
}

t_envp *create_e(char *key, char *value)
{
	t_envp	*new;

	new = (t_envp *)malloc(sizeof(t_envp));
	if (key)
		new->key = strdup(key);
	else
		new->key = NULL;
	if (value)
		new->value = strdup(value);
	else
		new->value = NULL;
	return (new);
}
int	main(void)
{
	g_minishell.envp = NULL;

	t_list	*envpl;
	t_envp	*envp;
	t_exec	*data;
	envpl = create_l();
	envp = create_e("a", NULL);
	g_minishell.envp = envpl;
	envpl->data = (void *)envp;

	envpl = create_l();
	envp = create_e("b", "test");
	g_minishell.envp->next = envpl;
	envpl->data = envp;

	envpl = create_l();
	envp = create_e("c", "hi");
	g_minishell.envp->next->next = envpl;
	envpl->data = envp;

	data = (t_exec*)malloc(sizeof(t_exec));
	data->cmd = strdup("env");
	data->cmd_path = strdup("/bin/env");
	data->cmd_argv = (char **)malloc(sizeof(char *) * 4);
	data->cmd_argv[0] = strdup("env");
	data->cmd_argv[1] =strdup("env");
	data->cmd_argv[2] = NULL;
	ft_env(data, 0);
}
#endif
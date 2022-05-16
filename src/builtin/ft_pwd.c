#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includehena/test.h"
// #include "../libft/libft.h"
#define TRUE 1
#define FALSE 0

/*
 *	option 무시이므로 뒤에 와도 무시할 예정
 *	pipe_flag : pipe exist
 */

extern t_minishell g_minishell;

static int	check_option(char *str)
{
	if (str[0] == '-')
		return (TRUE);
	else
		return (FALSE);
}

void	ft_pwd(t_exec *data, int pipe_flag)
{
	char	*now_path;
#if 0	// COMPILE ERROR
	int		ret;
#endif
	char	**argv;

	argv = data->argv;
	argv++;
	if (!argv && check_option(*argv))
	{
		// TODO:: ft_putendl_fd() 함수가 없으므로 헤더 추가하고 주석 풀어야 함
		// ft_putendl_fd(2, "option T.T\n");
		exit(1);
	}
	now_path = NULL;
	now_path = getcwd(NULL, 256);
	if (now_path == NULL)
	{
		// TODO:: ft_putendl_fd() 함수가 없으므로 헤더 추가하고 주석 풀어야 함
		// ft_putendl_fd("fail getcwd()\n", 2);
		exit(1);
		// exit(errno);// 숫자 어케할건지
	} 
	// TODO:: ft_putendl_fd() 함수가 없으므로 헤더 추가하고 주석 풀어야 함
	// ft_putendl_fd(now_path, 1);
	g_minishell.state = 0;
	free(now_path);
	if (pipe_flag)
		exit(0);
}

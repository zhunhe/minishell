#ifndef BUILT_IN_H
# define BUILT_IN_H

// 지워야 할듯
#include "./test.h"
/*
 *  ft_pwd.c file
 */
void	ft_pwd(t_exec *data, int pipe_flag);

/*
 *  ft_unset.c file
 */

void	ft_unset(t_exec	*data, int pipe_flag);

/*
 *  ft_env.c file
 */
void	ft_env(t_exec *data, int pipe_flag);

/*
 *  ft_exit.c file
 */
void	ft_exit(t_exec *data, int pipe_flag);

/*
 *  ft_cd.c file
 */
void	ft_cd(t_exec *data, int pipe_flag);

/*
 *  ft_exit_util.c file
 */
int	ft_atoi(char *str);
int	check_all_integer(char *str);
void	print_exit_error(char *str, int type);
unsigned char	calculate_exit_number(int exit_num);

/*
 *  cd_util.c
 */
void    change_global_oldpwd(char **prev);
void    change_envp_pwd();
void    change_envp_oldpwd();
void	change_values(char *now);
void	change_to_old_path(char *now);

#endif
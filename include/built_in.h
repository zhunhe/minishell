/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:02:14 by hena              #+#    #+#             */
/*   Updated: 2022/05/18 19:02:15 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# define TRUE 1
# define FALSE 0

# include "minishell.h"
# include "parse.h"

/*
 *  ft_pwd.c file
 */
void			ft_pwd(t_exec *data, int pipe_flag);

/*
 *  ft_exit.c file
 */
void			ft_exit(t_exec *data, int pipe_flag);

/*
 *  ft_exit_util.c file
 */

long long		ft_atoi(char *str);
int				check_all_integer(char *str);
void			print_exit_error(char *str, int type, int pipe_flag);
unsigned char	calculate_exit_number(int exit_num);

/*
 *  ft_echo.c file
 */
void			ft_echo(t_exec *data, int pipe_flag);

/*
 *  ft_env.c file
 */
void			ft_env(t_exec *data, int pipe_flag);

/*
 *  ft_unset.c file
 */

void			ft_unset(t_exec *data, int pipe_flag);

/*
 *  ft_export.c file
 */
void			ft_export(t_exec *data, int pipe_flag);
void			ft_print_export_error(char *argv);

/*
 *  ft_export_util.c file
 */

int				divide_argv(char **argv);

/*
 *  ft_export_util2.c
 */

t_list			*init_list(void);
t_envp			*init_envp(char *key, char *value);
char			*make_key(char *str, int len, int *i);
char			*make_value(char *str, int len, int index, int *i);
void			add_key_value(t_list *envpl, t_envp	*envp, char *key, \
char *value);

/*
 *  ft_cd.c file
 */

void			ft_cd(t_exec *data, int pipe_flag);

/*
 *  ft_cd_home.c
 */

char			*find_home_path(int *flag);
void			using_environment_home_value(char *now);
void			non_using_environment_value(char *now);
int				go_home_dir(char *argv, char *now);

/*
 *  ft_cd_util.c
 */

void			change_global_oldpwd(char *prev);
void			change_envp_pwd(void);
void			change_envp_oldpwd(void);
void			change_values(char *now);
void			change_to_old_path(char *now);

/*
 *  ft_cd_util2.c
 */
void			print_error_cd(char *path);

/*
 *  ft_cd_tilde.c
 */
void			use_tilde(char *str, char *now);

/*
 *  unlink.c
 */

void			unlink_all(t_list *heredoc);

/*
 *  set_exit_status.c
 */

int				set_exit_status(int status);
#endif

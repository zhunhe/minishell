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

/*
 *  ft_cd.c file
 */

void			ft_cd(t_exec *data, int pipe_flag);

/*
 *  ft_cd_home.c
 */

char	*find_home_path(int *flag);
void    using_environment_home_value(char *now);
void	non_using_environment_value(char *now);
int	go_home_dir(char *argv, char *now);

/*
 *  ft_cd_util.c
 */

void	        print_error_cd(char *path);
void			change_global_oldpwd(char **prev);
void			change_envp_pwd(void);
void			change_envp_oldpwd(void);
void			change_values(char *now);
void			change_to_old_path(char *now);

#endif

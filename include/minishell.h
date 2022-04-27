/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:32:02 by juhur             #+#    #+#             */
/*   Updated: 2022/04/27 14:59:09 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MINISHELL	"\e[01;32mminishell$ \e[0m"

/*
** prompt.c
*/
void	print_prompt(void);

/*
** echoctl.c
*/
void	echoctl_on(void);
void	echoctl_off(void);

/*
** split.c
*/
char	**_split(const char *s, const char c);

/*
** parse.c
*/
void	parse(char *s);
#endif
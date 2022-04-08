/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:32:02 by juhur             #+#    #+#             */
/*   Updated: 2022/04/08 21:07:50 by juhur            ###   ########.fr       */
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
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:15:49 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 10:20:11 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_LOGIC_H
# define MAIN_LOGIC_H
# include "parse.h"

void	main_logic(t_list *exec, t_list *heredoc);
void	fork_pipe(t_list *link, t_list *heredoc);
void	tree_traversal(t_node *tree, t_exec *data, \
int pipe_exist, t_list *heredoc);
void	end_setting(void);
#endif

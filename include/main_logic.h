/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:15:49 by hena              #+#    #+#             */
/*   Updated: 2022/05/18 22:15:51 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_LOGIC_H
# define MAIN_LOGIC_H
# include "parse.h"

int		main_logic(void);
void	fork_pipe(t_list *link);
void	tree_traversal(t_node *tree, t_exec *data, int type);

#endif

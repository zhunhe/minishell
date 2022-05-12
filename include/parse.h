/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:31:28 by juhur             #+#    #+#             */
/*   Updated: 2022/05/12 16:23:44 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "list.h"

typedef enum e_node_type
{
	TYPE_IN_OVERWRITE,
	TYPE_OUT_OVERWRITE,
	TYPE_HEREDOC,
	TYPE_OUT_APPEND,
	TYPE_CMD,
	TYPE_ETC
}	t_node_type;

/*
** ast.c
*/
t_node_type	get_type(char *str);

/*
** tokenize.c
*/
t_list		*tokenize(char *s);
#endif
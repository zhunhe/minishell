/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:22:10 by juhur             #+#    #+#             */
/*   Updated: 2022/05/14 14:56:24 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <util.h>

t_node	*create_node(char *data)
{
	t_node	*new;

	new = _calloc(sizeof(t_node), 1);
	new->type = get_type(data);
	return (new);
}

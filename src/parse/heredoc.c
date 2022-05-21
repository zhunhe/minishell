/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:52:49 by juhur             #+#    #+#             */
/*   Updated: 2022/05/21 17:18:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <parse.h>
#include <util.h>

static t_heredoc	*make_heredoc(t_node *node)
{
	t_heredoc	*heredoc;

	heredoc = _calloc(1, sizeof(t_heredoc));
	heredoc->end_string = _strdup(node->right->file_name);
	heredoc->file_name = _strdup("/tmp/hena_chan");
	heredoc->file_name = _strjoin_free(heredoc->file_name, _itoa(node->right->heredoc_idx), true);
	return (heredoc);
}

t_list	*get_heredoc(t_list *exec)
{
	t_list		*cur;
	t_list		*result;
	t_node		*node;

	cur = exec;
	result = NULL;
	while (cur != NULL)
	{
		node = ((t_exec *)cur->data)->root;
		while (node != NULL)
		{
			if (node->type == TYPE_HEREDOC)
				add_list_back(&result, create_list(make_heredoc(node)));
			node = node->left;
		}
		cur = cur->next;
	}
	return (result);
}
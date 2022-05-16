/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:12:33 by juhur             #+#    #+#             */
/*   Updated: 2022/05/17 07:58:36 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <list.h>
#include <parse.h>
#include <util.h>

#define PRINT		1

#if PRINT
void	print_ast(t_node *root) {
	t_node	*cur = root;

	printf("%s %d\n", __func__, __LINE__);
	while (cur != NULL)
	{
		printf("cur [%s] [%d]\n", cur->file_name, cur->type);
		if (cur->right)
			printf("right [%s] [%d]\n", cur->right->file_name, cur->right->type);
		cur = cur->left;
	}
}
#endif

void	set_ast(t_exec *result, char *s)
{
	if (get_type(s) == TYPE_ETC)
		add_node_right(&result->root, create_node(_strdup(s)));
	else
		add_node_root(&result->root, create_node(_strdup(s)));

}

void	set_data(t_exec *exec, int *heredoc_idx)
{
	t_node	*cur;
	t_node	*last;

	cur = exec->root;
	while (cur != NULL)
	{
		if (get_type(cur->file_name) == TYPE_HEREDOC)
		{
			exec->heredoc = true;
			if (cur->right != NULL)
				cur->right->heredoc_idx = ++(*heredoc_idx);
		}
		cur = cur->left;
	}
	last = get_last_left_node(exec->root);
	last->type = TYPE_CMD;
}

t_exec	*make_exec(t_list *token, int *heredoc_idx)
{
	t_exec	*result;
	char	**ss;

	result = _calloc(1, sizeof(t_exec));
	result->pipe_exist = true;
	while (token != NULL)
	{
		ss = _split((char *)token->data, ' ');
		if (result->cmd == NULL)
			set_cmd(result, ss);
		set_ast(result, ss[0]);
		token = token->next;
		_split_free(ss);
	}
	set_data(result, heredoc_idx);
#if PRINT
	print_ast(result->root);
	printf("*************************\n");
#endif
	return (result);
}

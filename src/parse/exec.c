/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:12:33 by juhur             #+#    #+#             */
/*   Updated: 2022/05/20 00:26:38 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <minishell.h>
#include <list.h>
#include <parse.h>
#include <util.h>

#define PRINT		0

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
		add_left_leaf_to_child(&result->root, create_node(_strdup(s)), false);
	else
		add_left_leaf_to_child(&result->root, create_node(_strdup(s)), true);

}

void	set_data(t_exec *exec, int *heredoc_idx, t_node *cmd_node, int *status)
{
	t_node	*cur;

	cur = exec->root;
	while (cur != NULL)
	{
		if (get_type(cur->file_name) == TYPE_HEREDOC)
		{
			exec->heredoc = true;
			if (cur->right != NULL)
				cur->right->heredoc_idx = ++(*heredoc_idx);
			if (*heredoc_idx > 16)
				*status = STATUS_HEREDOC_COUNT_ERROR;
		}
		cur = cur->left;
	}
	if (cmd_node != NULL)
		add_left_leaf_to_child(&exec->root, cmd_node, true);
}

t_exec	*make_exec(t_list *token, int *heredoc_idx, int *status)
{
	t_exec	*result;
	t_node	*cmd_node;
	char	**ss;

	result = _calloc(1, sizeof(t_exec));
	result->pipe_exist = true;
	cmd_node = set_cmd(result, (char *)token->data);
	if (cmd_node != NULL)
		token = token->next;
	while (token != NULL)
	{
		ss = _split((char *)token->data, ' ');
		set_ast(result, ss[0]);
		token = token->next;
		_split_free(ss);
	}
	set_data(result, heredoc_idx, cmd_node, status);
#if PRINT
	print_ast(result->root);
	printf("*************************\n");
#endif
	return (result);
}

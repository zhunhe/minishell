/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/10 17:34:52 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list.h>
#include <util.h>
#include <parse.h>
#include <minishell.h>

#define PRINT	1

#if PRINT
#include <stdio.h>
void	print_token(t_list *head)
{
	t_list	*cur;
	t_token	*token;

	cur = head;
	while (cur != NULL)
	{
		token = cur->data;
		printf("type[%d] data[%s]\n", token->type, token->data);
		cur = cur->next;
	}
}
#endif

void	remove_token(void *arg)
{
	t_token	*token;

	token = arg;
	free(token->data);
	free(token);
}

t_list	*tokenize(char *s)
{
	t_list		*head;
	t_list		*cur;
	t_token		*token;
	size_t		len;

	_strskip(&s, " ");
	head = NULL;
	while (*s != '\0')
	{
		cur = _calloc(1, sizeof(t_list));
		token = _calloc(1, sizeof(t_token));
		cur->data = token;
		token->type = get_type(s);
		switch (token->type)
		{
			case TYPE_OUT_APPEND:
			case TYPE_HEREDOC:
				token->data = _strndup(s, 2);
				s += 2;
				break;
			case TYPE_IN_OVERWRITE:
			case TYPE_OUT_OVERWRITE:
				token->data = _strndup(s, 1);
				++s;
				break;
			default:
				len = _strcharset(s, "<>") - s;
				token->data = _strndup(s, len);
				s += len;
				break;
		}
		add_list_back(&head, cur);
		_strskip(&s, " ");
	}
#if PRINT
	print_token(head);
	printf("------------------\n");
#endif
	return (head);
}
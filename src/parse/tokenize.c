/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:02:20 by juhur             #+#    #+#             */
/*   Updated: 2022/05/12 16:20:56 by juhur            ###   ########.fr       */
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

	cur = head;
	while (cur != NULL)
	{
		printf("data[%s]\n", cur->data);
		cur = cur->next;
	}
}
#endif

t_list	*tokenize(char *s)
{
	t_list		*head;
	t_list		*cur;
	char		*data;
	size_t		len;

	_strskip(&s, " ");
	head = NULL;
	while (*s != '\0')
	{
		cur = _calloc(1, sizeof(t_list));
		switch (get_type(s))
		{
			case TYPE_OUT_APPEND:
			case TYPE_HEREDOC:
				data = _strndup(s, 2);
				s += 2;
				break;
			case TYPE_IN_OVERWRITE:
			case TYPE_OUT_OVERWRITE:
				data = _strndup(s, 1);
				++s;
				break;
			default:
				len = _strcharset(s, "<>") - s;
				data = _strndup(s, len);
				s += len;
				break;
		}
		cur->data = data;
		add_list_back(&head, cur);
		_strskip(&s, " ");
	}
#if PRINT
	print_token(head);
	printf("------------------\n");
#endif
	return (head);
}
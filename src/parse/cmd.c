/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:40:02 by juhur             #+#    #+#             */
/*   Updated: 2022/05/17 07:41:19 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <util.h>

void	set_cmd(t_exec *result, char **ss)
{
	result->cmd = _strdup(ss[0]);
	// TODO: envp의 PATH의 value값을 ':' 기준으로 split한 후 open해보고 열리는 문자열을 반환. 없으면 NULL
	// result->cmd_path =
	// TODO: splitted된 char **ss를 _strjoin을 이용해 붙여주는 작업 필요함. {"CMD", "-n(option)", "-n(option)", "string"}
	// result->cmd_argv =
}
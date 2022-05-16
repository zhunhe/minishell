/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:00:52 by hena              #+#    #+#             */
/*   Updated: 2022/05/12 05:00:54 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H
#include "../includehena/test.h"
/*
 *input.c
 */

void	input(char *filename, int dup_fd);

/*
 *output.c
 */

void	output(char *filename, int dup_fd);
void	output_append(char *filename, int dup_fd);

/*
 *  heredoc.c
 */

void	here_doc(int index, int dup_fd);

#endif

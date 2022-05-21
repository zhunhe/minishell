/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 05:00:52 by hena              #+#    #+#             */
/*   Updated: 2022/05/20 10:04:03 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H
/*
 *  input.c		<
 */

void	input(char *filename, int dup_fd);

/*
 *  output.c	>, >>
 */

void	output(char *filename, int dup_fd);
void	output_append(char *filename, int dup_fd);

/*
 *  heredoc.c	<<
 */

void	here_doc(int index, int dup_fd, t_list *heredoc);

/*
 *  heredoc_input.c
 */

int		run_heredoc(t_list *iter);

#endif

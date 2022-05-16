/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hena <hena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 02:18:42 by hena              #+#    #+#             */
/*   Updated: 2022/05/12 02:18:43 by hena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

void	sig_cmd_int_handler(int signal);
void	sig_cmd_quit_handler(int signal);
void	sig_heredoc_handler(int signal);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:57:32 by juhur             #+#    #+#              #
#    Updated: 2022/04/27 14:58:43 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror

READLINE_DIR = $(shell brew --prefix readline)
READLINE_AR = $(READLINE_DIR)/lib
READLINE_INC = $(READLINE_DIR)/include
READLINE = -lreadline -L$(READLINE_AR) -I$(READLINE_INC)

MINISHELL_INC_DIR = ./include
MINISHELL_INC = $(MINISHELL_INC_DIR)/minishell.h

SRC_DIR = ./src
SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
	prompt.c \
	echoctl.c \
	split.c \
	parse.c \
	ast.c \
	util.c \
)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c $(MINISHELL_INC)
	$(CC) $(CFLAGS) -I$(READLINE_INC) -I$(MINISHELL_INC_DIR) -c $< -o $@

$(NAME) : $(OBJS) $(MINISHELL_INC)
	$(CC) $(CFLAGS) $(READLINE) -I$(MINISHELL_INC_DIR) $(OBJS) -o $@

.PHONY : all, clean, fclean, re
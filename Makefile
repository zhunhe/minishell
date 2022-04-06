# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:57:32 by juhur             #+#    #+#              #
#    Updated: 2022/04/06 16:08:27 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror

READLINE_DIR = $(shell brew --prefix readline)
READLINE_AR = $(READLINE_DIR)/lib
READLINE_INC = $(READLINE_DIR)/include

INC_DIR = ./include
HEADER = $(INC_DIR)/minishell.h

SRC_DIR = ./src
SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -I$(READLINE_INC) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -lreadline -L$(READLINE_AR) -I$(READLINE_INC) $(OBJS) -o $@

.PHONY : all, clean, fclean, re
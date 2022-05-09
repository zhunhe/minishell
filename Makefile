# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:57:32 by juhur             #+#    #+#              #
#    Updated: 2022/05/09 13:42:28 by juhur            ###   ########.fr        #
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
ROOT_SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
)

PARSE_DIR = $(SRC_DIR)/parse
PARSE_SRCS = $(addprefix $(PARSE_DIR)/, \
	ast.c \
	envp.c \
	error.c \
	parse.c \
)

PROMPT_DIR = $(SRC_DIR)/prompt
PROMPT_SRCS = $(addprefix $(PROMPT_DIR)/, \
	echoctl.c \
	prompt.c \
)

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	list.c \
	split.c \
	stdlib.c \
	string.c \
	strchr.c \
	strskip.c \
)

SRCS = \
	$(ROOT_SRCS) \
	$(PARSE_SRCS) \
	$(PROMPT_SRCS) \
	$(UTIL_SRCS)

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
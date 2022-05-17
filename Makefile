# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 15:57:32 by juhur             #+#    #+#              #
#    Updated: 2022/05/16 17:06:12 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

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

BUILTIN_DIR = $(SRC_DIR)/builtin
BUILTIN_SRCS = $(addprefix $(BUILTIN_DIR)/, \
	cd_util1.c \
	cd.c \
	check_string_util.c \
	echo.c \
	exit_util.c \
	exit.c \
	ft_env.c \
	ft_export.c \
	ft_pwd.c \
	ft_unset.c \
)

PIPE_SIGNAL_DIR = $(SRC_DIR)/pipe_signal
PIPE_SIGNAL_SRCS = $(addprefix $(PIPE_SIGNAL_DIR)/, \
	signal_cmd.c \
	signal_here.c \
)

PIPES_DIR = $(SRC_DIR)/pipes
PIPES_SRCS = $(addprefix $(PIPES_DIR)/, \
	alone_cmd.c \
	main_logic.c \
	pipe.c \
)

REDIRECTION_DIR = $(SRC_DIR)/redirection
REDIRECTION_SRCS = $(addprefix $(REDIRECTION_DIR)/, \
	heredoc_input.c \
	heredoc.c \
	input.c \
	output.c \
)

PARSE_DIR = $(SRC_DIR)/parse
PARSE_SRCS = $(addprefix $(PARSE_DIR)/, \
	envp.c \
	error.c \
	exec.c \
	parse.c \
	tokenize.c \
)

PROMPT_DIR = $(SRC_DIR)/prompt
PROMPT_SRCS = $(addprefix $(PROMPT_DIR)/, \
	echoctl.c \
	prompt.c \
)

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRCS = $(addprefix $(UTIL_DIR)/, \
	ast.c \
	calloc.c \
	list.c \
	split.c \
	strcharset.c \
	strchr.c \
	strdup.c \
	strlcat.c \
	strlen.c \
	strncmp.c \
	strndup.c \
	strskip.c \
	strcmp.c \
	putstr_fd.c \
	putendl_fd.c
)

SRCS = \
	$(ROOT_SRCS) \
	$(BUILTIN_SRCS) \
	$(PIPE_SIGNAL_SRCS) \
	$(PIPES_SRCS) \
	$(REDIRECTION_SRCS) \
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
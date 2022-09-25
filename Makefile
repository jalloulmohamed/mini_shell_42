# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjalloul <mjalloul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 16:37:17 by babkar            #+#    #+#              #
#    Updated: 2022/09/25 17:06:21 by mjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minishell

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC = minishell.c \
	src/sh_execute.c \
	src/utils.execute.c\
	src/xsh_signals.c \
	src/xsh_env.c \
	src/simplecommand.c \
	src/syntaxe1_error.c \
	src/syntaxe2_error.c \
	src/lvl_and_or.c  \
	src/utils.c \
	src/utils_2.c \
	src/lvl_pipe.c \
	src/utils_pipe.c\
	src/utils_disperse_cmd.c \
	src/expend_heredoc.c \
	src/expend_dolar.c \
	src/expend_wildcards.c \
	src/red_cmd.c \
	src/utils_red.c\
	src/heredoc_utils.c \
	src/builtins/builtins_utils.c \
	src/builtins/builtins.c \
	src/builtins/cd.c \
	src/builtins/echo.c \
	src/builtins/env.c \
	src/builtins/exit.c \
	src/builtins/export_utils.c \
	src/builtins/export.c \
	src/builtins/pwd.c \
	src/builtins/unset.c \
	src/utils/bubble_sort_dlst.c \
	src/utils/char_count.c \
	src/utils/ft_atoi.c \
	src/utils/ft_bzero.c \
	src/utils/ft_calloc.c \
	src/utils/ft_fork.c \
	src/utils/ft_isalpha.c \
	src/utils/ft_isdigit.c \
	src/utils/ft_itoa.c \
	src/utils/ft_memset.c \
	src/utils/ft_putstr_fd.c \
	src/utils/ft_split.c \
	src/utils/ft_strchr.c \
	src/utils/ft_strcmp.c \
	src/utils/ft_strdup.c \
	src/utils/ft_strjoin_char.c \
	src/utils/ft_strjoin.c \
	src/utils/ft_strlen.c \
	src/utils/ft_strtrim.c \
	src/utils/ft_strunite.c \
	src/utils/ft_substr.c \
	src/utils/garbage.c \
	src/utils/puterr.c \
	src/utils/remove_extra_quotes.c \
	src/utils/t_var.c \
	src/utils/t_env.c \
	src/utils/t_node.c \

BUILD_DIR := ./Build

OBJ := $(SRC:%=$(BUILD_DIR)/%.o)

LDFLAGS := -L$(shell brew --prefix readline)/lib -lreadline

CPPFLAGS := -I$(shell brew --prefix readline)/include

all : $(NAME)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(CPPFLAGS) -c $< -o $@
	
$(NAME) : $(OBJ)
		$(CC) -g -fsanitize=address $(LDFLAGS) $(OBJ) -o $(NAME) -lreadline

clean:
		rm -rf $(BUILD_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all
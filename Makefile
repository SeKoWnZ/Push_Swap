# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 13:41:46 by jose-gon          #+#    #+#              #
#    Updated: 2024/05/06 11:58:47 by jose-gon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
FLAGS =  -g -Wall -Wextra -Werror -I./include
LFLAGS = -L./include/Libft -lft

FILES = push_swap.c cleaner.c check_args.c node_push.c node_reverse_r.c \
node_rotate.c node_swap.c sortit_move.c push_swap_utils.c join_args.c \
split_args.c stack_creator.c status_b_to_a.c sort_it.c

B_FILES = checker_bonus.c node_push_bonus.c node_reverse_r_bonus.c \
node_rotate_bonus.c node_swap_bonus.c check_args_bonus.c join_args_bonus.c \
split_args_bonus.c stack_creator_bonus.c cleaner_bonus.c

SRC_DIR = src
SRC_B = src_bonus
OBJ_DIR = obj
SOURCES = $(FILES:%=$(SRC_DIR)/%)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
B_SOURCES = $(B_FILES:%=$(SRC_B)/%)
B_OBJECTS = $(patsubst $(SRC_B)/%.c, $(OBJ_DIR)/%.o, $(B_SOURCES))

all: libft $(NAME)

libft:
	@$(MAKE) -C ./include/Libft

$(NAME): $(OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./include/push_swap.h
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(B_OBJECTS)
	gcc $(FLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_B)/%.c ./include/checker_bonus.h
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C ./include/Libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C ./include/Libft fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: bonus all clean fclean re libft

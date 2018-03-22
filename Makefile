# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 15:32:05 by mjose             #+#    #+#              #
#    Updated: 2017/12/12 12:42:58 by mjose            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fillit

NOC = \033[0m
OKC = \033[32m
ERC = \033[31m
WAC = \033[33m

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRC_PATH = ./fillit_src/
OBJ_PATH = ./fillit_src/obj/
INC_PATH = ./fillit_src/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fillit.h

SRC_NAME = arrange.c check.c main.c read.c shape.c solve.c tetrimino.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L $(LFT_PATH) -lft
	@echo "$(WAC)FILLIT STATUS:\t\t$(OKC)Ready$(NOC)"
	@echo "======"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -I $(SRC_PATH) -o $@ -c $<
	@echo -n =

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FILLIT:\t\t\tRemoving binaries folder.$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FILLIT:\t\t\tRemoving executable.$(NOC)"

re: fclean all

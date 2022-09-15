# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 11:20:04 by altikka           #+#    #+#              #
#    Updated: 2022/09/15 17:02:07 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INCS = -I./includes -I./libft -I./libft/ft_printf/includes

SRC_DIR = src/
SRCS = $(SRC_DIR)main.c \
	   $(SRC_DIR)init_data.c \
	   $(SRC_DIR)clean_up.c

OBJ_DIR = obj/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

FLGS = -Wall -Wextra -Werror

LIB_PATH = -L libft/ -lft

EOC = \033[0m
LGRAY = \033[38;5;244m
SAL = \033[38;5;203m
SILVER = \033[38;5;247m
BLACK = \033[38;5;236m
WHITE = \033[38;5;231m
GREEN = \033[38;5;70m
RED = \033[38;5;124m

all: $(NAME)

$(NAME):
	@echo "$(EOC)"
	@echo "     [ L ] "
	@echo "    /     \ "
	@echo " [ E ]   [ M ] "
	@echo "   |       | "
	@echo "   |     [ I ] "
	@echo "    \     / "
	@echo "     [ N ]$(BLACK) by altikka$(EOC)"
	@echo ""
	@make -C ./libft
	@mkdir -p $(OBJ_DIR)
	@echo "$(LGRAY)[lem_in] $(GREEN)Creating files...$(EOC)"
	@gcc -c $(FLGS) $(SRCS) $(INCS)
	@mv *.o $(OBJ_DIR)
	@echo "$(LGRAY)[lem_in] $(GREEN)Compiling...$(EOC)"
	@gcc -o $(NAME) $(OBJS) $(INCS) $(LIB_PATH)
	@echo "$(LGRAY)[lem_in] $(GREEN)Compiled successfully!"

clean:
	@make -C ./libft/ clean
	@echo "$(LGRAY)[lem_in] $(SAL)Deleting object directory...$(EOC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./libft/ fclean
	@echo "$(LGRAY)[lem_in] $(SAL)Executable $(WHITE)$(NAME)$(EOC) $(SAL)removed!$(EOC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

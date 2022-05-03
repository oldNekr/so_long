# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 09:09:43 by lrosby            #+#    #+#              #
#    Updated: 2022/03/18 09:09:46 by lrosby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT	= \033[0;39m
GREEN	= \033[0;92m
BLUE	= \033[0;94m
CYAN	= \033[0;96m
RED		= \033[0;91m

# Make variables
CC			= cc
CFLAGS		= -Wextra -Werror -Wall
RM			= rm -rf
MKD			= mkdir -p
MLX_FLAGS	= -framework OpenGL -framework AppKit

INC	= inc/so_long.h
LIBFT = -L ./libft/bin/ -lft
MLX_LIB = -L ./mlx/ -lmlx
GNL_LIB = -L ./get_next_line/bin/ -lgnl

SRC_DIR	= src
OBJ_DIR	= obj
BIN_DIR	= bin

BIN		= so_long
NAME	= $(BIN_DIR)/$(BIN)
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

SRC		= so_long.c checker.c loading_map.c initialization.c move.c\

# Basic maps
SRC_MAPS = map.ber	map_smal.ber\

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -lt 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# Make Commands
all:	$(NAME)

$(NAME): mandatory

mandatory: create_dirs maker $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT) $(GNL_LIB) -o $(NAME)
	@printf "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC)
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

create_dirs:
	@$(MKD) $(BIN_DIR)
	@$(MKD) $(OBJ_DIR)

maker:
	@make -C libft
	@make -C get_next_line
	@make -C mlx

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C libft
	@make clean -C get_next_line
	@make clean -C mlx
	@printf "$(CYAN)Cleaning up object files in $(BIN)...$(DEFAULT)\n"

fclean:		clean
	@$(RM) $(BIN_DIR)
	@make fclean -C libft
	@make fclean -C get_next_line
	@printf "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

re:			fclean all

norm:
	@printf "$(CYAN)\nCheking norm for $(BIN)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) inc

git:
	git add .
	git commit -m lipa
	git push

.PHONY:	all clean fclean re create_dirs maker norm git
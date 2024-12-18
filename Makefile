# --------------------------EXEC AND COMPILATION---------------------------- #

EXEC = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE_DIR = include/

# ------------------------SOURCES AND OBJS DIRECTORY------------------------ #

CONT_DIR = ./src/content/
SRC_MANDATORY =	error_free.c \
				parsing.c \
				test.c \
				main.c

SRC = $(addprefix $(CONT_DIR), $(SRC_MANDATORY))
OBJ_DIR = so_obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

# ------------------------------SOURCE FILES------------------------------- #

MLX_DIR = minilibx-linux/
MLX = libmlx_Linux.a
MLX_NAME = $(addprefix $(MLX_DIR), $(MLX))
MLX_FLAG = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lXext -lX11 -lm -lz $(MLX)
MLX_EXEC = $(MLX_NAME) $(MLX_FLAG)

LIBFT_DIR = src/libft/src
LIBFT = libft.a
LIBFT_NAME = $(addprefix $(LIBFT_DIR), $(LIBFT))
LIBFT_FLAG = -L $(LIBFT_DIR)

# ---------------------------------COMMAND--------------------------------- #

all: $(EXEC)

# -----------------CALL LIBFT AND MLX------------------ #

libft:
	@echo "\e[1;34mCompiling$(LIBFT_DIR)...\e[0m"
	@make -C $(LIBFT_DIR)
	@echo "\e[1;92mDone.\e[0m"

mlx:
	@echo "\e[1;34mCompiling $(MLX_DIR)...\e[0m"
	@make -sC $(MLX_DIR)
	@echo "\e[1;92mDone.\e[0m"

# -------------------CREATE LIBRARY-------------------- #

$(EXEC): libft mlx $(OBJ)
	@echo "\e[1;34mCompiling...\n\e[0m"
	$(CC) $(OBJ) $(LIBFT_NAME) $(MLX_EXEC) -o $(EXEC)
	@echo "\e[1;92mExecutable $(EXEC) created successfully.\n\e[0m"

# -------------------COMPILATION .o-------------------- #

$(OBJ_DIR)%.o:%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(HEAD) -c $< -o $(OBJ_DIR)$(notdir $@)

# ---------------------RULES--------------------- #

clean:
	@echo "\e[1;34mmDeleting obj in $(MLX_DIR)\n.\e[0m"
	@make clean -sC $(MLX_DIR)
	@echo "\e[1;34mDeleting obj in $(LIBFT_DIR).\e[0m"
	@make clean -sC $(LIBFT_DIR)
	@echo "\e[1;91mDone.\n\e[0m"
	@echo "\e[1;34mDeleting obj...\n\e[0m"
	@rm -rf $(OBJ_DIR)
	@echo "\e[1;91mDone.\n\e[0m"

fclean: clean
	@echo "\e[1;34mDeleting .a and exec.\n\e[0m"
	@rm -rf $(EXEC)
	@echo "\e[1;91mfclean was executed successfully.\e[0m"

re: fclean all

.PHONY: all clean fclean re libft mlx
# --------------------------NAME OF FILES CREATED--------------------------- #

EXEC = so_long
NAME = so_long.a
NAME_DIR = head/

# -------------------------------COMPILATION-------------------------------- #

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = include/
HEAD = -I $(INCLUDE) -I $(MLX_DIR)

# ------------------------SOURCES AND OBJS DIRECTORY------------------------ #

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), parsing.c)
OBJ_DIR = so_obj/
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# ------------------------------SOURCE FILES------------------------------- #

MAIN = main.c
MAIN_OBJ = $(OBJ_DIR)main.o

MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx_Linux.a
MLX_FLAG = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lXext -lX11 -lm -lz $(MLX)

LIBFT_DIR = src/libft/src
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_FLAG = -L $(LIBFT_DIR)

# ---------------------------------COMMAND--------------------------------- #

all: $(EXEC) mlx

# --------------------CALL LIBFT.a--------------------- #

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

mlx:
	$(MAKE) -sC $(MLX_DIR)

# ---------------------CREATE EXEC--------------------- #

$(EXEC): $(OBJ) $(MAIN_OBJ) $(NAME) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(MAIN_OBJ) $(OBJ) $(NAME_DIR)$(NAME) $(LIBFT_FLAG) $(MLX_FLAG) -o $(EXEC)
	echo "\e[1;92mExecutable $(EXEC) created successfully.\e[0m"

# -------------------CREATE LIBRARY-------------------- #

$(NAME): $(LIBFT) mlx $(OBJ)
	@mkdir -p $(NAME_DIR)
	@ar -rcs $(NAME_DIR)$(NAME) $(OBJ)
	@echo "\e[1;92mLibrary $(NAME) created successfully.\e[0m"

# -------------------COMPILATION .o-------------------- #

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(HEAD) -c $< -o $@

$(MAIN_OBJ): $(MAIN)
	@$(CC) $(FLAGS) $(HEAD) -c $(MAIN) -o $(MAIN_OBJ)

# ---------------------RULES--------------------- #

clean:
	@rm -rf $(OBJ_DIR)

clean_libft:
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean clean_libft
	@rm -rf $(NAME_DIR) $(EXEC)
	@echo "\e[1;91mfclean was executed successfully.\e[0m"

re: fclean all

.PHONY: all clean fclean re
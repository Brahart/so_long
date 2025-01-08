BOLD_GREEN	= \e[1;32m
BOLD_RED	= \e[1;31m
BOLD_BLUE	= \e[1;34m
STOP_COLOR	= \e[0m

EXEC 		= so_long

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror -g

HEAD 		= include/so_long.h

LIBFT_DIR 	= src/libft/src/
LIB_LIBFT 	= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) $(LIB_LIBFT)

MLX_DIR 	= minilibx-linux/
LIB_MLX 	= $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS	= -L $(MLX_DIR) -I $(MLX_DIR) -lmlx_Linux -lX11 -lXext $(LIB_MLX)
# -L is for linking the directory of mlx
# -lX11 and -lXext is for linking some different graphic library require by the mlx 

SRC_DIR 	= src/content/
SRC_FILE 	=	init_image.c \
				main.c \
				map.c \
				player_movement.c \
				rendered.c \
				set_params.c \
				utils.c \
				verif_map.c

SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_DIR 	= obj/
OBJ 		= $(SRC:%.c=%.o)
OBJ_LIBFT 	= $(OBJ_DIR)*.o


all: $(EXEC)

$(OBJ_DIR)%.o: %.c $(HEAD)
	@$(CC) $(FLAGS) -c $< -o $@


$(EXEC): $(OBJ)
	@echo "$(BOLD_BLUE)Make Libft...$(STOP_COLOR)"
	@make -sC $(LIBFT_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Make Mlx...$(STOP_COLOR)"
	@make -sC $(MLX_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Creating executable so_long...$(STOP_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(EXEC)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"

clean:
	@echo "$(BOLD_BLUE)Delete obj...$(STOP_COLOR)"
	@make clean -sC src/libft/src/
	@make clean -sC minilibx-linux/
	@rm -f $(SRC_DIR)*.o
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

fclean: clean
	@echo "$(BOLD_BLUE)Make fclean...$(STOP_COLOR)"
	@rm -f $(LIB_LIBFT) $(LIB_MLX) $(EXEC)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

re: fclean all

.PHONY: all clean fclean re
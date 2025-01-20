BOLD_GREEN	= \e[1;32m
BOLD_RED	= \e[1;31m
BOLD_BLUE	= \e[1;34m
STOP_COLOR	= \e[0m

NAME 		= so_long

CC 			= cc
FLAGS 		= -Wall -Wextra -Werror -g3

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
SRC_FILE 	=	end.c \
				init_image.c \
				main.c \
				map_utils.c \
				map.c \
				player_movement.c \
				rendered.c \
				set_params.c \
				utils.c \
				verif_map.c

SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_DIR 	= objs/
OBJ 		= $(SRC_FILE:%.c=$(OBJ_DIR)%.o)


all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJ)
	@echo "$(BOLD_BLUE)Make Libft...$(STOP_COLOR)"
	@make -sC $(LIBFT_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Make Mlx...$(STOP_COLOR)"
	@make -sC $(MLX_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Creating executable so_long...$(STOP_COLOR)"
	@$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"

clean:
	@echo "$(BOLD_BLUE)Delete obj...$(STOP_COLOR)"
	@make clean -sC src/libft/src/
	@make clean -sC minilibx-linux/
	@rm -rf $(OBJ_DIR)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

fclean: clean
	@echo "$(BOLD_BLUE)Make fclean...$(STOP_COLOR)"
	@rm -f $(LIB_LIBFT) $(LIB_MLX) $(NAME)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

re: fclean all

.PHONY: all clean fclean re

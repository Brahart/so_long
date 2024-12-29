EXEC 		= so_long

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror -g
MLX_FLAGS	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# -L is for linking the directory of mlx
# -lX11 and -lXext is for linking some different graphic library require by the mlx 


HEAD 		= include/so_long.h

LIBFT_DIR 	= src/libft/src/
LIB_LIBFT 	= $(LIBFT_DIR)libft.a

MLX_DIR 	= minilibx-linux/
LIB_MLX 	= $(MLX_DIR)libmlx.a

SRC_DIR 	= src/content/
SRC_FILE 	=	set_params.c \
				error_free.c \
				main.c \
				map.c \
				verif_map.c

SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_DIR 	= obj/
OBJ 		= $(SRC:%.c=%.o)
OBJ_LIBFT 	= $(OBJ_DIR)*.o


all: $(LIB_LIBFT) $(LIB_MLX) $(EXEC)

$(OBJ_DIR)%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_LIBFT):
	make -sC $(LIBFT_DIR)

$(LIB_MLX):
	make -sC $(MLX_DIR)

$(EXEC): $(OBJ)
	$(CC) $(FLAGS) $(OBJ_LIBFT) $(OBJ) -o $(EXEC)

clean:
	make clean -sC src/libft/src/
	make clean -sC minilibx-linux/
	rm -f $(SRC_DIR)*.o

fclean: clean
	rm -f $(LIB_LIBFT)
	rm -f $(LIB_MLX)
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:02:00 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/08 00:59:41 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../minilibx-linux/mlx.h"
// # include "../minilibx-linux/mlx_int.h"
# include "../src/libft/include/libft.h"
# include "../src/libft/include/ft_printf.h"
# include "../src/libft/include/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
// # include <X11/keysym.h>
// # include <X11/X.h>

# define IMG_HEIGHT 64
# define IMG_WIDTH 64

# define FLOOR "assets/floor.xpm"
# define WALL "assets/wall.xpm"
# define ENEMY "assets/enemy.xpm"
# define COLLECTIBLE "assets/collectible.xpm"
# define EXIT "assets/exit.xpm"
# define EXIT_OPEN "assets/exit.xpm"
# define PLAYER_UP "assets/player/player_up.xpm"
# define PLAYER_DOWN "assets/player/player_down.xpm"
# define PLAYER_LEFT "assets/player/player_left.xpm"
# define PLAYER_RIGHT "assets/player/player_right.xpm"

# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

typedef struct pos_s
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	x;
	int	y;
}	t_pos;

typedef struct enemy_s 
{
    int		x;
	int		y;
    int		direction_x;
    int		direction_y;
    int 	speed;
	t_pos	pos;
}	t_enemy;

typedef struct player_s 
{
	int		line;
	int		col;
    int		width;
	int		height;
	t_pos	pos;
}	t_player;


typedef struct content_s
{
	char	wall;
	char	space;
	char	player;
	char	enemy;
	char	exit;
	char	collectible;
	int		count_ex;
	int		count_p;
	int		count_c;
	int		count_en;
}	t_cont;

typedef struct img_s
{
	void	*sprite;
	void	*img_wall;
	void	*img_space;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_enemy;
	char	*wall;
	char	*space;
	char	*player;
	char	*exit;
	char	*collectible;
	char	*enemy;
	int		img_height;
	int		img_width;
}	t_image;

typedef struct data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			width;
	int			height;
	char		**map;
	int			player_render;
	t_cont		content;
	t_image		img;
	t_image		floor;
	t_image		wall;
	t_image		enemy;
	t_image		collectible;
	t_image		exit;
	t_image		exit_open;
	t_image		player_up;
	t_image		player_down;
	t_image		player_left;
	t_image		player_right;
	t_pos		pos;
	t_enemy		*enemy;
	t_player	player;
	int			count;
}	t_data;

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
void	set_content(t_cont *content);
char	**verif_map(char **arg, t_data *data);
void	check_content(t_data *data);
int		check_content_map(char *line, t_cont content);
int		check_column(char *line, char wall, t_data *data);
int		check_line(char *line, char wall);
int		check_is_rectangle(char **map);
void	free_map(t_data *data);
void	set_content(t_cont *content);
void	set_assets(t_data *data);
void	init_window(t_data *data);
int		end_game(t_data *data);
int		keyboard_key(int key, t_data *data);
void	ft_error(const char *str);
int		check_collect(t_data *data);
int		is_ber(char *str, const char *ber);
void	rendered_enemy(t_data *data);
void	print_img(t_data *data, t_image img, int x, int y);
void	ft_win(int moves);
void	rendered_move(t_data *data, int y, int x, int render);
void	rendered_player(t_data *data, int x, int y);
void	rendered_background(t_data *data);
void	rendered_other(t_data *data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:02:00 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/06 18:22:56 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define ENEMY_MAX 30

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../src/libft/include/libft.h"
# include "../src/libft/include/ft_printf.h"
# include "../src/libft/include/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct pos_s
{
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
	t_cont		content;
	t_image		img;
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
void	print_img(t_data *data, void *img, int x, int y);
void	rendered_top(t_data *data);
void	rendered_down(t_data *data);
void	rendered_right(t_data *data);
void	rendered_left(t_data *data);
int		check_collect(t_data *data);
int		is_ber(char *str, const char *ber);
void	rendered_enemy(t_data *data);
void	ft_win(int moves);

#endif
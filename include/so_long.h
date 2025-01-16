/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:02:00 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/16 15:56:36 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../src/libft/include/libft.h"
# include "../src/libft/include/ft_printf.h"
# include "../src/libft/include/get_next_line.h"
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define FLOOR "assets/floor.xpm"
# define WALL "assets/wall.xpm"
# define ENEMY "assets/enemy.xpm"
# define COLLECTIBLE "assets/collectible.xpm"
# define EXIT "assets/exit.xpm"
# define EXIT_OPEN "assets/exit_open.xpm"
# define PLAYER_UP "assets/player/player_up.xpm"
# define PLAYER_DOWN "assets/player/player_down.xpm"
# define PLAYER_LEFT "assets/player/player_left.xpm"
# define PLAYER_RIGHT "assets/player/player_right.xpm"

typedef struct pos_s
{
	int	x;
	int	y;
}	t_pos;

typedef struct content_s
{
	char	wall;
	char	space;
	char	player;
	char	enemy;
	char	exit;
	char	collectible;
	int		count_c;
	int		tmp_c;
	int		count_ex;
	int		tmp_ex;
	int		count_p;
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
	char		**flood;
	t_cont		content;
	t_image		img;
	t_pos		pos;
	int			count;
	int			x;
	int			y;
}	t_data;

			/* LIBFT */
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
			/* PARSING */
char	**verif_map(char **arg, t_data *data);
void	check_content(t_data *data);
int		check_is_rectangle(char **map);
int		check_line(char *line, char wall, t_data *data);
int		check_column(char *line, char wall, t_data *data);
int		check_content_map(char *line, t_cont content);
void	check_flood_fill(t_data *data);
int		verif_double_backspace(char *line);
			/* SET CONTENT */
void	set_content(t_cont *content);
void	set_assets(t_data *data);
void	set_image(t_data *data);
			/* INIT IMAGE */
void	init_window(t_data *data);
int		rendered(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
void	destroy_image(t_data *data);
			/* MOUVEMENT */
int		keyboard_key(int key, t_data *data);
void	player_rend(t_data *data, int pos_y, int pos_x, char *sprite);
			/* END */
int		end_game(t_data *data);
void	ft_free(t_data *data);
			/* UTILS */
void	ft_error(const char *str);
void	ft_win(int moves);
int		check_collect(t_data *data);
void	flood_fill(t_data *data, int x, int y);
int		is_ber(char *str, const char *ber);
void	free_map(char **map);
void	free_map_and_exit(char **map);

#endif
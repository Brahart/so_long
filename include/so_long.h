/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:02:00 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/30 17:57:09 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct player_pos_s
{
	int	x;
	int	y;
}	t_player_pos;

typedef struct content_s
{
	char	wall;
	char	space;
	char	player;
	char	exit;
	char	collectible;
	int		count_e;
	int		count_p;
	int		count_c;
}	t_cont;

typedef struct img_s
{
	void	*img_wall;
	void	*img_space;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	char	*wall;
	char	*space;
	char	*player;
	char	*exit;
	char	*collectible;
	int		img_height;
	int		img_width;
}	t_image;

typedef struct data_s
{
	void			*mlx_ptr;
	void			*mlx_win;
	int				width;
	int				height;
	char			**map;
	t_cont			content;
	t_image			img;
	t_player_pos	pos;
	int				count;
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
void	set_image(t_data *data);
void	init_window(t_data *data);
int		end_game(t_data *data);
int		keyboard_key(int key, t_data *data);
void	ft_error(const char *str);
void	rendered_top(t_data *data);
void	rendered_down(t_data *data);
void	rendered_right(t_data *data);
void	rendered_left(t_data *data);
int		check_collect(t_data *data);
int		is_ber(char *str, const char *ber);

#endif
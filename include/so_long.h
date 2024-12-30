/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:02:00 by asinsard          #+#    #+#             */
/*   Updated: 2024/12/30 01:06:48 by abrahamsins      ###   ########lyon.fr   */
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
void	ft_check_content(t_data *data);
int		ft_check_content_map(char *line, t_cont content);
int		ft_check_column(char *line, char wall);
int		ft_check_line(char *line, char wall);
int		ft_check_is_rectangle(char **map);
void	ft_error(const char *str);
void	set_content(t_cont *content);
char	**ft_verif_map(char **arg, t_data *data);
char	**ft_parse_map(int fd, t_data *data);
void	ft_free_map(t_data *data);
char	*ft_extract_map(int fd);

#endif
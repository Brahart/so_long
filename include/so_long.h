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

typedef struct	content_s
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

typedef	struct	data_s
{
	int		width;
	int		height;
	char	**map;
	t_cont	content;
	int		count;
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
void	ft_error(char *str);
void	set_content(t_cont *content);
char	**ft_verif_map(char **arg, t_data *data);
char	**ft_parse_map(int fd, t_data *data);
void	ft_free_map(t_data *data);
char	*ft_extract_map(int fd);

#endif
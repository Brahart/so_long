#include "include/so_long.h"

int	main(void)
{
	void	*ptr;
	void	*win;
	void	*img;
	int		width = 10;
	int		height = 10;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 1920, 1080, "test");
	img = mlx_xpm_file_to_image(ptr, "assets/test.xpm", &width, &height);
	mlx_put_image_to_window(ptr, win, img, 10, 10);
	mlx_loop(ptr);
}
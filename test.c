#include "so_long.h"

int my_key_funct(int keycode, void *param)
{
    int i;

    i = 0;
    printf("key event %d\n", i);
    i++;
    return (0);
}

int main(void)
{
    void    *mlx;
    void    *win;
    int     x;
    int     y;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 1920, 1080, "test");
    y = 100;
    while (y < 300)
    {
        x = 100;
        while (x < 300)
        {
            mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
            x++;
        }
        y++;
    }
    mlx_key_hook(win, my_key_funct, 0);
    mlx_loop(mlx);
}
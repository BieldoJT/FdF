#include "fdf.h"

void	mlx_creation(t_mlx *mlx)
{
	t_img	*image;

	mlx->img = malloc(sizeof(t_img));
	image = mlx->img;
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr,WIDTH,HEIGHT,"my window");
	image->ptr = mlx_new_image(mlx->mlx_ptr,WIDTH,HEIGHT);
	image->addr = mlx_get_data_addr(image->ptr, &image->bits_per_pixel,\
		&image->line_length,&image->endian);
}

int	close_win(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx_ptr,mlx->img->ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx->img);
	free(mlx);
	ft_printf("fechou\n");
	exit(EXIT_SUCCESS);

	return 0;
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;
	t_img	*img;

	img = mlx->img;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel/8));
	*(unsigned int *)dst = color;
}

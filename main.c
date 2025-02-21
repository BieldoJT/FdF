#include "fdf.h"

void free_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr,mlx->img->ptr);

}

int	close_win(t_mlx *vars)
{

	mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
	free_img(vars);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	free(vars->img);
	free(vars);
	ft_printf("fechou");
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


int main ()
{
	t_mlx	*fdf_mlx;


	fdf_mlx = malloc(sizeof(t_mlx));
	fdf_mlx->img = malloc(sizeof(t_img));

	fdf_mlx->mlx_ptr = mlx_init();
	fdf_mlx->mlx_win = mlx_new_window(fdf_mlx->mlx_ptr,500,300,"my window");


	fdf_mlx->img->ptr = mlx_new_image(fdf_mlx->mlx_ptr,500,300);

	fdf_mlx->img->addr = mlx_get_data_addr(fdf_mlx->img->ptr, &fdf_mlx->img->bits_per_pixel, &fdf_mlx->img->line_length,&fdf_mlx->img->endian);

	my_mlx_pixel_put(fdf_mlx, 5, 5, 0x00FF0000);







	mlx_put_image_to_window(fdf_mlx->mlx_ptr, fdf_mlx->mlx_win, fdf_mlx->img->ptr, 0, 0);
	mlx_hook(fdf_mlx->mlx_win,17,0,close_win, fdf_mlx);
	mlx_loop(fdf_mlx->mlx_ptr);
	return 0;
}

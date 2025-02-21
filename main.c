#include "fdf.h"


void	print_rectangle(t_mlx *mlx , double size_x, double size_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_x)
	{
		my_mlx_pixel_put(mlx, 10 + i, 10, 0x00FF0000);
		my_mlx_pixel_put(mlx, 10 + i, 10 + size_y, 0x00FF0000);
		i++;
	}
	while (j < size_y)
	{
		my_mlx_pixel_put(mlx, 10, 10 + j, 0x00FF0000);
		my_mlx_pixel_put(mlx, 10 + size_x, 10 + j, 0x00FF0000);
		j++;
	}

}
//0x009800 verda
void print_triangle(t_mlx *mlx, double base, double height)
{
	double	hip;
	double	i;
	double	x;
	double	cosseno_x;
	//double	cosseno_y;

	hip = hypot(base / 2, height);
	cosseno_x = cos((base / 2) / hip);
	//cosseno_y = cos(height / hip);
	i = 0;
	x = 0;
	while (x <= (base / 2))
	{
		my_mlx_pixel_put(mlx, 200 + x, 200, 0x009800);
		my_mlx_pixel_put(mlx, 200 + x, 200 - (i * cosseno_x), 0x009800);
		i += 0.1;
		x += 0.1;
	}
	while (x < base)
	{
		my_mlx_pixel_put(mlx, 200 + x, 200, 0x009800);
		my_mlx_pixel_put(mlx, 200 + x, 200 - (i * cosseno_x), 0x009800);
		i -= 0.1;
		x += 0.1;
	}
}



int	main (void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx_creation(mlx);

	//my_mlx_pixel_put(mlx, 5, 5, 0x00FF0000); // pixel put melhorado
	print_rectangle(mlx , 50, 70);
	print_triangle(mlx,50,200);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img->ptr, 0, 0);
	mlx_hook(mlx->mlx_win,17,0,close_win, mlx);
	mlx_loop(mlx->mlx_ptr);
	return 0;
}

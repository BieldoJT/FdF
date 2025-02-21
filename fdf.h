#ifndef FDF_H
# define FDF_H

# include "libraries/Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*img;
}	t_mlx;

# define WIDTH 500
# define HEIGHT 300

//mlx_config.c
void	mlx_creation(t_mlx *mlx);
int		close_win(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

#endif

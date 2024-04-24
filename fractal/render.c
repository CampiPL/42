/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:10:14 by ubuntu            #+#    #+#             */
/*   Updated: 2024/04/24 13:58:26 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.r = 0;
	z.i = 0;
	c.r = map(x, -2, 2, WIDTH);
	c.i = map(y, -2, 2, HEIGHT);
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC1);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

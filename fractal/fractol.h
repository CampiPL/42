/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:23:48 by kuba              #+#    #+#             */
/*   Updated: 2024/04/24 13:52:08 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800

# define BLACK   0x000000
# define WHITE   0xFFFFFF
# define RED     0xFF0000
# define GREEN   0x00FF00
# define BLUE    0x0000FF
# define YELLOW  0xFFFF00
# define CYAN    0x00FFFF
# define MAGENTA 0xFF00FF
# define ORANGE  0xFFA500
# define PURPLE  0x800080
# define PINK    0xFFC0CB
# define GRAY    0x808080

# define PSYCHEDELIC1  0xFF00FF
# define PSYCHEDELIC2  0xFFFF00
# define PSYCHEDELIC3  0x00FFFF
# define PSYCHEDELIC4  0xFFA500
# define PSYCHEDELIC5  0x800080
# define PSYCHEDELIC6  0xFFC0CB
# define PSYCHEDELIC7  0xFF1493
# define PSYCHEDELIC8  0x00FF

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
}	t_fractal;

void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
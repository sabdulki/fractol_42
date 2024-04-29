/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:03 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/10 17:09:01 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	which_fractol(t_info *fractol, t_complex_num *z, t_complex_num *c)
{
	if (fractol->is_mandel == 1)
	{
		c->r = z->r;
		c->i = z->i;
	}
	else if (fractol->is_julia == 1)
	{
		c->r = fractol->julia_x;
		c->i = fractol->julia_y;
	}
}

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	pixel_position;

	pixel_position = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + pixel_position) = color;
}

static void	check_pixels(t_info *fractol, int x, int y)
{
	t_complex_num	z;
	t_complex_num	c;
	int				iter;
	double			color;

	iter = 0;
	z.r = (scale(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.i = (scale(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	which_fractol(fractol, &z, &c);
	while (iter < fractol->f_calls)
	{
		z = sum_complex_nums(square_complex_num(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractol->out_of_fractol)
		{
			color = scale(iter, fractol->c.c1, fractol->c.c2, fractol->f_calls);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		iter++;
	}
	my_pixel_put(x, y, &fractol->img, fractol->c.cent_c);
}

void	draw_fractol(t_info *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			check_pixels(data, x, y);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
}

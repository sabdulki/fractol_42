/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:53:03 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/02 19:39:50 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// for MANDELBROT

// z = z^2 + c

// the very first z is 0, 0 (r = 0, i = 0)
// c is an actual point -> i change pixels place 
// to the changed scale (0 -> -2)

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	// Пример установки цвета пикселя в позиции (x, y)
	// int color = 0x00FF00; // Пример цвета в формате RGB (зеленый)

	int pixel_position = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + pixel_position) = color;

	
	// int bits_per_pixel = img->bpp / 8;
	// offset = (y * img->line_len) + (x * bits_per_pixel);
	// *(unsigned int *)&img->pixels_ptr[offset] = color;

	// img->pixels_ptr[offset / (img->bpp / 8)] = color;

}

static void check_pixels(t_info *fractol, int x, int y)
{
	t_complex_num z;
	t_complex_num c;
	int iter;
	double color_res;

	iter = 0;

	z.r = (change_scale(x, -2, 2, 0, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.i = (change_scale(y, 2, -2, 0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	
	if (!ft_strncmp(fractol->title, "mandelbrot", 10))
	{
		c.r = z.r;
		c.i = z.i;
	}
	else if (!ft_strncmp(fractol->title,  "julia", 5))
	{
		c.r = fractol->julia_x;
		c.i = fractol->julia_y;
	}
	// z.r = 0.0;
	// z.i = 0.0; 

	// how many times itarate the formula. number of iterations
	while (iter < fractol->how_many_iterations) // call the function 
	{
		z = sum_complex_nums(square_complex_num(z), c);
		
		if ((z.r * z.r) + (z.i * z.i) > fractol->out_of_fractol)
		{
			color_res = change_scale(iter, fractol->colors.color1, fractol->colors.color2, 0, fractol->how_many_iterations);
			my_pixel_put(x, y, &fractol->img, color_res);
			return ;
		}
		iter++;
	}
	my_pixel_put(x, y, &fractol->img, fractol->colors.cent_c);
}

void draw_fractol(t_info *data)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT) 
	{
		x = -1;
		while (++x < WIDTH)
		{
			check_pixels(data, x, y);
			// x++;
		}
		// y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
}

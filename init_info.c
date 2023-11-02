/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:24:38 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/02 19:37:35 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_info *init_info_struct(char *name)
{
	t_info *d;

	d = malloc(sizeof(t_info)); //data
	if (!d)
		ft_error_mlx(d);
	d->mlx = mlx_init();
	if (!d->mlx)
		ft_error_mlx(d);
	d->title = name;
	d->mlx_win = mlx_new_window(d->mlx, WIDTH, HEIGHT, d->title);
	if (!d->mlx_win)
	{
		ft_error_mlx(d);
	}
	d->img.img_ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	if (!d->img.img_ptr)
	{
		// mlx_destroy_image(d->mlx, d->img.img_ptr);
		mlx_destroy_window(d->mlx, d->mlx_win);
		ft_error_mlx(d);
	}

	// the most importatnt - get addres of pixels
	// because exactly addresses of pixels form the img
	d->img.pixels_ptr = mlx_get_data_addr(d->img.img_ptr, &d->img.bpp, &d->img.line_len, &d->img.endian);

	d->shift_x = 0.0;
	d->shift_y = 0.0;
	d->out_of_fractol = 4; //hypotenose
	d->how_many_iterations = 42;
	d->zoom = 1.0; // factor in multipications

	d->colors.color1 = YELLOW;
	d->colors.color2 = RED;
	d->colors.cent_c = BLACK;
	return (d);
}

int free_info_struct(t_info *data)
{
	if (data == NULL)
		return (0);
	if (data->mlx)
		free(data->mlx);
	// if (data->mlx_win)
	// 	free(data->mlx_win);
	free(data);
	data = NULL;
	
	return (0);
}
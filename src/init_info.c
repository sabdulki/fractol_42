/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:24:38 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/10 17:48:08 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_additional_info(t_info *d)
{
	d->is_mandel = 0;
	d->is_julia = 0;
	d->shift_x = 0.0;
	d->shift_y = 0.0;
	d->out_of_fractol = 4;
	d->f_calls = 42;
	d->zoom = 1.0;
	d->mouse_x = 0.0;
	d->mouse_y = 0.0;
	d->c.c1 = YELLOW;
	d->c.c2 = RED;
	d->c.cent_c = BLACK;
}

t_info	*init_info_struct(char *name)
{
	t_info	*d;

	d = malloc(sizeof(t_info));
	d->title = name;
	if (!d)
		ft_error_mlx(d);
	d->mlx = mlx_init();
	if (!d->mlx)
		ft_error_mlx(d);
	d->mlx_win = mlx_new_window(d->mlx, WIDTH, HEIGHT, d->title);
	if (!d->mlx_win)
		ft_error_mlx(d);
	d->img.img_ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	if (!d->img.img_ptr)
	{
		mlx_destroy_window(d->mlx, d->mlx_win);
		ft_error_mlx(d);
	}
	d->img.pixels_ptr = mlx_get_data_addr(d->img.img_ptr,
			&d->img.bpp, &d->img.line_len, &d->img.endian);
	if (!d->img.pixels_ptr)
		ft_error_mlx(d);
	init_additional_info(d);
	return (d);
}

int	free_info_struct(t_info *data)
{
	if (data == NULL)
		return (0);
	if (data->mlx)
		free(data->mlx);
	free(data);
	data = NULL;
	return (0);
}

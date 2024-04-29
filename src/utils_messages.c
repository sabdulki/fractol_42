/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:32:36 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/09 15:34:38 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_mlx(t_info *d)
{
	free_info_struct(d);
	ft_printf("problems with initialization of the t_info struct");
	exit(0);
}

void	print_err(void)
{
	ft_printf("\tINVALID INPUT\n\tYour options are: 'mandelbrot', 'julia'.");
	ft_printf(" Use 2 parametrs(a, bi) for julia from -2 to 2.\n");
	ft_printf("\tExample 1: ./fractol mandelbrot\n");
	ft_printf("\tExample 2: ./fractol julia -0.8 0.18");
	exit(0);
}

int	close_window(t_info *data)
{
	ft_printf("	The program has been successfully closed");
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_info_struct(data);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:25 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/02 19:36:52 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char**argv)
{
	t_info *data;
	char *name;

	if (((argc != 2) && (!ft_strncmp(argv[1], "mandelbrot", 10)))
		|| ((argc != 4) && (!ft_strncmp(argv[1], "julia" , 5))))
	{
		ft_printf("INVALID INPUT\nYour options are: 'mandelbrot', 'julia'.");
		ft_printf("Use 2 parametrs(x,y) for julia from -1 to 1.\n");
		ft_printf("Example 1: ./fractol mandelbrot\nExample 2: ./fractol julia -0.8 0.18");
		exit(0);
	}
	name = argv[1];
	data = init_info_struct(name);
	if (!ft_strncmp(data->title, "julia", 5))
	{
		data->julia_x = atodbl(argv[2]);
		data->julia_y = atodbl(argv[3]);
	}
	draw_fractol(data);
	hooks(data);
	mlx_loop(data->mlx);
}
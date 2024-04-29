/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:25 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/10 17:00:43 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char**av)
{
	t_info	*data;
	int		is_mandelbrot;
	int		is_julia;

	if (argc < 2)
		print_err();
	is_mandelbrot = ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 1;
	is_julia = ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 1;
	if ((is_mandelbrot == 1 && argc != 2) || (is_julia == 1 && argc != 4) || \
		(is_julia && (is_d(av[2]) == 0 || is_d(av[3]) == 0)) || \
		(!is_julia && !is_mandelbrot))
		print_err();
	data = init_info_struct(av[1]);
	if (is_mandelbrot == 1)
		data->is_mandel = 1;
	if (is_julia == 1)
	{
		data->is_julia = 1;
		data->julia_x = atodbl(av[2]);
		data->julia_y = atodbl(av[3]);
	}
	draw_fractol(data);
	hooks(data);
	mlx_loop(data->mlx);
}

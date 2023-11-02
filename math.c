/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:22:05 by sabdulki          #+#    #+#             */
/*   Updated: 2023/10/27 04:16:34 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_num sum_complex_nums(t_complex_num z1, t_complex_num z2)
{
	t_complex_num res;

	res.r = z1.r + z2.r;
	res.i = z1.i + z2.i;
	return (res);
}

t_complex_num square_complex_num(t_complex_num z)
{
	t_complex_num res;

	res.r = (z.r * z.r) - (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}

double	change_scale(double unscaled_num, double new_min, double new_max,
					double old_min, double old_max)
{
	double new_diff;
	double old_diff;
	double unsc_pl; // place in old range of the unscaled num
	// that we will change

	new_diff = (new_max - new_min);
	old_diff = (old_max - old_min);
	unsc_pl = (unscaled_num - old_min);
	return (((new_diff * unsc_pl) / old_diff) + new_min);
}
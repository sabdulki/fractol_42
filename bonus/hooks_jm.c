/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_jm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:20:19 by sabdulki          #+#    #+#             */
/*   Updated: 2024/04/29 17:24:44 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/fractol.h"

int	hooks(t_info *d)
{
	mlx_hook (d->mlx_win, 02, 1L << 0, hook_keypress, d);
	mlx_hook (d->mlx_win, 04, 1L << 2, hook_zoom, d);
	mlx_hook (d->mlx_win, 17, 1L << 17, close_window, d);
	mlx_hook (d->mlx_win, 03, 1L << 0, color_hooks, d);
	mlx_hook(d->mlx_win, 6, 1L<<6, julia_moves, d);

	return (0);
}

int	color_hooks(int keysym, t_info *d)
{
	if (keysym == 18)
	{
		d->c.c1 = YELLOW;
		d->c.c2 = RED;
	}
	if (keysym == 19)
	{
		d->c.c1 = CYAN;
		d->c.c2 = BLUE;
	}
	if (keysym == 20)
	{
		d->c.c1 = VIOLET;
		d->c.c2 = PURPLE;
	}
	if (keysym == 21)
	{
		d->c.c1 = MY_BLUE;
		d->c.c2 = DEEP_BLUE;
	}
	if (keysym == 18 || keysym == 19 || keysym == 20 || keysym == 21)
		draw_fractol(d);
	return (0);
}

int	hook_keypress(int keysym, t_info *d)
{
	if (keysym == 13)
		d->c.cent_c = WHITE;
	if (keysym == 11)
		d->c.cent_c = BLACK;
	if (keysym == 53)
		close_window(d);
	if (keysym == 126)
		d->shift_y += (0.5 * d->zoom);
	if (keysym == 125)
		d->shift_y -= (0.5 * d->zoom);
	if (keysym == 124)
		d->shift_x += (0.5 * d->zoom);
	if (keysym == 123)
		d->shift_x -= (0.5 * d->zoom);
	if (keysym == 13 || keysym == 11 || keysym == 126 || \
		keysym == 125 || keysym == 124 || keysym == 123)
		draw_fractol(d);
	return (0);
}

int	hook_zoom(int btn, int x, int y, t_info *d)
{
	d->mouse_x = (double)x;
	d->mouse_y = (double)y;
	if (btn == 5)
	{
		d->zoom *= 1.12;
		draw_fractol(d);
	}
	else if (btn == 4)
	{
		d->zoom /= 1.12;
		draw_fractol(d);
	}
	return (0);
}


int julia_moves(int x, int y, t_info* d)
{
	d->julia_x = scale(x, -2, 2, WIDTH) * d->zoom + d->shift_x;
	d->julia_y = scale(y, 2, -2, HEIGHT) * d->zoom + d->shift_y;
	draw_fractol(d);
	return (0);
}
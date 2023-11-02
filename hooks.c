/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:20:19 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/02 18:47:52 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int hooks(t_info *d)
{
	mlx_hook(d->mlx_win, 03, 1L<<0, hook_keypress, d);
	mlx_hook(d->mlx_win, 04, 1L<<2, hook_zoom, d);
	mlx_hook(d->mlx_win, 17, 1L<<17, close_window, d);
	mlx_hook(d->mlx_win, 6, 1L<<6, julia_moves, d);
	mlx_hook(d->mlx_win, 02, 1L<<0, color_hooks, d);
	return (0);
}

int color_hooks(int keysym, t_info *d)
{
	if (keysym == 13) // W, white
		d->colors.cent_c = WHITE;
	if (keysym == 11) // B, black
		d->colors.cent_c = BLACK;
	if (keysym == 18) // 1 in the row
	{
		d->colors.color1 = YELLOW;
		d->colors.color2 = RED;
		d->colors.cent_c = BLACK;
	}
	if (keysym == 19) // 2 in the row
	{
		d->colors.color1 = CYAN;
		d->colors.color2 = BLUE;
	}
	if (keysym == 20) // 3 in the row
	{
		d->colors.color1 = VIOLET;
		d->colors.color2 = PURPLE;
	}
	if (keysym == 21) // 4 in the row
	{
		d->colors.color1 = MY_BLUE;
		d->colors.color2 = DEEP_BLUE;
	}
	draw_fractol(d);
	return (0);
}

int hook_keypress(int keysym, t_info *d)
{
	// ft_printf("%d\n", keysym);
	if (keysym == 53) // esc
		close_window(d);
	if (keysym == 126) // shift up
		d->shift_y += (0.5 * d->zoom);
	if (keysym == 125) // shift down
		d->shift_y -= (0.5 * d->zoom);
	if (keysym == 124) // shift right
		d->shift_x += (0.5 * d->zoom);
	if (keysym == 123) // shift left
		d->shift_x -= (0.5 * d->zoom);
	draw_fractol(d);
	return (0);
}

int hook_zoom(int btn, int x, int y, t_info *d)
{
	if (btn == 5) // scroll up
		d->zoom *= 1.95;
	else if (btn == 4) // scroll down
		d->zoom *= 0.95;
	draw_fractol(d);
	return (0);
}

int julia_moves(int x, int y, t_info* d)
{
	d->julia_x = change_scale(x, -2, 2, 0, WIDTH) * d->zoom + d->shift_x;
	d->julia_y = change_scale(y, 2, -2, 0, HEIGHT) * d->zoom + d->shift_y;
	draw_fractol(d);
	return (0);
}

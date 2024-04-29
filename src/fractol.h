/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:18:05 by sabdulki          #+#    #+#             */
/*   Updated: 2024/04/29 17:25:38 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h" 
# include "./ft_printf/ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define VIOLET 0x7423FD
# define PURPLE 0xF665FF
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define BLUE 0x0000FF
# define MY_BLUE 0x0027FF
# define DEEP_BLUE 0x011FC3
# define CYAN 0x00FFFF

# define HEIGHT 650
# define WIDTH 650

typedef struct s_color{
	unsigned int	c1;
	unsigned int	c2;
	unsigned int	cent_c;
}	t_color;

typedef struct s_img{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_info{
	int		is_mandel;
	int		is_julia;
	char	*title;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_color	c;
	int		out_of_fractol;
	int		f_calls;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	julia_x;
	double	julia_y;
	double	mouse_x;
	double	mouse_y;
}	t_info;

typedef struct s_complex_num{
	double	r;
	double	i;
}	t_complex_num;

t_complex_num	sum_complex_nums(t_complex_num z1, t_complex_num z2);
t_complex_num	square_complex_num(t_complex_num z);
t_info			*init_info_struct(char *name);
void			draw_fractol(t_info *data);
void			ft_error_mlx(t_info *data);
void			print_err(void);
int				free_info_struct(t_info *data);
int				hook_keypress(int keysym, t_info *d);
int				close_window(t_info *data);
int				hooks(t_info *d);
int				hook_zoom(int button, int x, int y, t_info *d);
int				color_hooks(int keysym, t_info *d);
int				ft_strncmp(char *s1, char *s2, size_t n);
size_t			ft_strlen(const char *str);
size_t			is_d(const char *str);
double			atodbl(char *s);
double			scale(double unscaled_num, double new_min,
					double new_max, double old_max);
int 			julia_moves(int x, int y, t_info* d);
#endif
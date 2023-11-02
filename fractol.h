/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:18:05 by sabdulki          #+#    #+#             */
/*   Updated: 2023/11/02 19:40:51 by sabdulki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h" 
# include "./ft_printf/ft_printf.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// colors
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

# define HEIGHT 700
# define WIDTH 700

typedef struct s_color{
	unsigned int color1;
	unsigned int color2;
	unsigned int cent_c;
}	t_color;

typedef struct s_img{
	void *img_ptr;
	char *pixels_ptr;
	int bpp; // bits per pixel
	int line_len; // width of window in bites. for memory offset
	int endian; //bites order
}	t_img;

typedef struct s_info{
	char *title;
	void *mlx; //mlx_init()
	void *mlx_win; //mlx_new_window()
	t_img img;
	t_color colors;
	// unsigned int scale;
	int out_of_fractol;
	int how_many_iterations;
	double zoom;
	double shift_x;
	double shift_y;
	double  julia_x;
	double  julia_y;
	// int keycode;
} t_info;

typedef struct s_complex_num{
	double r; // real num
	double i; // imaginary num
} t_complex_num;

//init
t_info *init_info_struct(char *name);
int free_info_struct(t_info *data);

// render
void draw_fractol(t_info *data);

//hooks
int hook_keypress(int keysym, t_info *d);
int close_window(t_info *data);
int hooks (t_info *d);
int hook_zoom(int buttin, int x, int y, t_info *d);
int julia_moves(int x, int y, t_info *d);
int color_hooks(int keysym, t_info *d);

//math
double change_scale(double unscaled_num, double new_min, double new_max,
					double old_min, double old_max);
t_complex_num sum_complex_nums(t_complex_num z1, t_complex_num z2);
t_complex_num square_complex_num(t_complex_num z);

//utils
void ft_error_mlx(t_info *data);
int	ft_strncmp(char *s1, char *s2, size_t n);
double	atodbl(char *s);

//colors & gradient
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
unsigned char	get_t(int trgb);
int	create_rgb(unsigned char r, unsigned char g, unsigned char b, unsigned char t);

#endif
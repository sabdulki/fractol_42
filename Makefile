# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 18:03:10 by sabdulki          #+#    #+#              #
#    Updated: 2023/11/02 19:47:53 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractol.c hooks.c init_info.c render.c math.c utils.c
OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g3 -fsanitize=address

MLX = cd mlx && make

PRINTF = ./ft_printf/libftprintf.a 

NAME = fractol

$(NAME): $(OBJ)
#	cd libft && make && make bonus
#	$(CC) $(OBJS) $(CFLAGS) libft/libft.a -o $(NAME)
#	cd libft && make && make bonus
	$(MLX)
	cd ft_printf && make
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean : 
	rm -f fractol $(OBJ)
#	cd libft && make clean
	cd ft_printf && make clean
	$(MAKE) clean -C mlx

fclean : clean
	rm -f $(NAME)
#	cd libft && make fclean
	cd ft_printf && make fclean

re : fclean all
#	cd libft && make fclean && make all
	cd ft_printf && make fclean && make all

.PHONY : all clean fclean re bonus


# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 18:03:10 by sabdulki          #+#    #+#              #
#    Updated: 2023/11/10 18:09:18 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = fractol.c hooks.c init_info.c render.c math.c utils.c utils_messages.c
OBJ = $(SRCS:.c=.o)

CC = cc
CFLAGS =  -Wall -Wextra -Werror

MLX = cd mlx && make

PRINTF = ./ft_printf/libftprintf.a 

NAME = fractol

$(NAME): $(OBJ)
	$(MLX)
	cd ft_printf && make
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean : 
	rm -f fractol $(OBJ)
	cd ft_printf && make clean
	$(MAKE) clean -C mlx

fclean : clean
	rm -f $(NAME)
	cd ft_printf && make fclean

re : fclean all
	cd ft_printf && make fclean && make all

.PHONY : all clean fclean re bonus

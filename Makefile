# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulki <sabdulki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 18:03:10 by sabdulki          #+#    #+#              #
#    Updated: 2024/04/29 17:26:03 by sabdulki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ./src/fractol.c \
		./src/init_info.c \
		./src/render.c \
		./src/math.c \
		./src/utils.c \
		./src/utils_messages.c

MAND_SRCS = ./mandatory/hooks.c
BONUS_SRCS = ./bonus/hooks_jm.c

OBJ = $(SRCS:.c=.o)
MAND_OBJ = $(MAND_SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# MLX = cd src/mlx && make

PRINTF = src/ft_printf/libftprintf.a 

NAME = fractol

$(NAME): $(OBJ) $(MAND_OBJ)
	cd mlx && make
	cd src/ft_printf && make
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) $(MAND_OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	cd mlx && make
	cd src/ft_printf && make clean
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) $(BONUS_OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean : 
	rm -f $(OBJ) $(MAND_OBJ) $(BONUS_OBJ)
	cd src/ft_printf && make clean
	$(MAKE) clean -C mlx

fclean : clean
	rm -f $(NAME)
	cd src/ft_printf && make fclean

re : fclean all

.PHONY : all clean fclean re bonus

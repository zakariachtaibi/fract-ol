# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchtaibi <zchtaibi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 22:13:41 by zchtaibi          #+#    #+#              #
#    Updated: 2024/04/22 14:09:42 by zchtaibi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS =  -Wall -Werror -Wextra 

NAME = fractol

SRC	=  math_utils.c render_burning_ship.c\
			render_julia.c render_mandelbrot.c\
			utils.c fractol.c init.c events.c\
			 

OBJS = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) -fsanitize=address -lmlx -framework OpenGL -framework AppKit -o $(NAME)
  
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
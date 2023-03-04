# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 23:57:58 by bel-kase          #+#    #+#              #
#    Updated: 2023/03/04 23:58:00 by bel-kase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES =  get_next_line/*.c so_long.c draw.c maps.c move_keywords.c map_2d.c Flood_fill.c

NAME = so_long

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -lmlx -fsanitize=address -g3 -framework OpenGL -framework AppKit

all : $(NAME) 

$(NAME):
	$(CC)  $(CFLAGS) $(CFILES)  -o so_long
		
clean : 
			${RM} ${NAME}
fclean : clean

re : fclean all
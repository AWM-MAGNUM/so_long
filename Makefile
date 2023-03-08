# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 01:28:21 by bel-kase          #+#    #+#              #
#    Updated: 2023/03/08 00:39:41 by bel-kase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES =  get_next_line.c get_next_line_utils.c so_long.c draw.c maps.c move_keywords.c map_2d.c Flood_fill.c func_libft.c func_libft_so_long.c ft_printf.c

CC = cc 

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3

all : $(NAME) 

$(NAME): $(CFILES)
	$(CC)  $(CFLAGS) $(CFILES)  -o so_long
		
clean : 
			${RM} ${NAME}
fclean : clean

re : fclean all
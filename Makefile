# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kase <bel-kase@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 01:28:21 by bel-kase          #+#    #+#              #
#    Updated: 2023/03/10 04:09:54 by bel-kase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES =  get_next_line.c get_next_line_utils.c so_long.c draw.c maps.c move_keywords.c map_2d.c Flood_fill.c func_libft.c func_libft_so_long.c ft_printf.c

BFILES = ./Bonus/get_next_line.c ./Bonus/get_next_line_utils.c ./Bonus/so_long.c ./Bonus/draw.c ./Bonus/maps.c ./Bonus/move_keywords.c \
./Bonus/map_2d.c ./Bonus/Flood_fill.c ./Bonus/func_libft.c ./Bonus/func_libft_so_long.c ./Bonus/ft_printf.c ./Bonus/360.c

CC = cc 

RM = rm -rf

BONUS = so_long_bonus

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

all : $(NAME) 

$(NAME): $(CFILES)
	$(CC)  $(CFLAGS) $(CFILES)  -o so_long
	
bonus :	$(BONUS)

$(BONUS): $(BFILES)
	$(CC) $(CFLAGS) $(BFILES) -o so_long_bonus
clean : 
			${RM} ${NAME}  ${BONUS}
fclean : clean

re : fclean all bonus
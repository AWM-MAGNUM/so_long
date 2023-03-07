NAME = so_long

CFILES =  get_next_line/*.c so_long.c draw.c maps.c move_keywords.c map_2d.c Flood_fill.c func_libft_so_long.c ft_printf/*.c

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
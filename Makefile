CFILES =  get_next_line/*.c so_long.c ft_strlen.c draw.c maps.c deplacer_a_ws_d.c

NAME = so_long

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -lmlx  -framework OpenGL -framework AppKit

all : $(NAME) 

$(NAME):
	$(CC)  $(CFLAGS) $(CFILES)  -o so_long
		
clean : 
			${RM} ${NAME}
fclean : clean

re : fclean all
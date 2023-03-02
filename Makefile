CFILES =  get_next_line/*.c read_map.c ft_strlen.c utils.c draw.c

NAME = so_long

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -lmlx  -framework OpenGL -framework AppKit

all : $(NAME) 

$(NAME):
	$(CC)  $(CFLAGS) $(CFILES)  -o so_long
		
clean : 
			${RM} ${NAME}
fclean : clean

re : fclean all
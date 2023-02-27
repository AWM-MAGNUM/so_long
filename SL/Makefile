CFILES =  get_next_line/*.c ft_strjoin.c ft_strdup.c read_map.c ft_strlen.c

NAME = so_long

CC = gcc 

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -lmlx  -framework OpenGL -framework AppKit

all : $(NAME) 

$(NAME):
	$(CC)  $(CFLAGS) $(CFILES)  -o so_long
		
clean : 
			${RM} ${NAME} ${BONUS}
fclean : clean

re : fclean all
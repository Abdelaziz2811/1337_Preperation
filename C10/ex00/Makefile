NAME = ft_display_file
SRC  = ft_display_file.c
OBJ  = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

NAME    = libft.a
SRC_DIR = srcs
INC_DIR = includes
SRC     = $(wildcard $(SRC_DIR)/*.c)
OBJ     = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	cc -Wall -Wextra -Werror -I $(INC_DIR) -c $< -o $@	

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

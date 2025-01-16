.PHONY: all clean fclean re

FILES = ft_printf.c \
		print_char.c \
		print_string.c \
		print_pointer.c \
		print_integer.c \
		print_unsigned.c \
		print_hexa.c

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
OBJ = $(FILES:.c=.o)



all: $(NAME)

$(NAME): $(OBJ)
	ar cr $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ) $(NAME)

re: fclean all

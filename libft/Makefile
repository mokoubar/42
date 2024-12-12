.PHONY: all clean fclean re

FILES =   ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c\
		ft_isdigit.c  ft_isprint.c  ft_memcpy.c  ft_memchr.c  ft_memcmp.c  ft_memmove.c\
		ft_memset.c  ft_strchr.c  ft_strdup.c  ft_strlcat.c  ft_strlcpy.c  ft_strlen.c\
		ft_strncmp.c  ft_strnstr.c  ft_strrchr.c  ft_substr.c ft_tolower.c  ft_toupper.c\
		ft_strtrim.c  ft_strjoin.c  ft_split.c  ft_itoa.c  ft_strmapi.c  ft_striteri.c\
		ft_putchar_fd.c  ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c

NAME = libft.a

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

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(FILES)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

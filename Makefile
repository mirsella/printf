SRCS = ft_printf.c parse.c putstr.c putnbr.c putptr.c puthex.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

bonus: all

dev: $(NAME)
	@$(CC) $(CFLAGS) main.c libftprintf.a

.PHONY: all clean fclean re dev bonus

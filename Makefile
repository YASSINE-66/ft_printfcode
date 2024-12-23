NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFILES = ft_printf.c printf_functions2.c printf_functions.c

OBJS = $(CFILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
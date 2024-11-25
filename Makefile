CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c ft_handlers.c ft_strlen.c ft_base.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c libftprintf
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
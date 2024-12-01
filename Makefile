CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c ft_strchr.c ft_handlers.c ft_strlen.c ft_base.c
SRCB = hashtag_bonus.c base_hashtag_bonus.c space_bonus.c base_space_bonus.c plus_bonus.c base_plus_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

bonus : $(OBJB)
	ar -rc $(NAME) $(OBJB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
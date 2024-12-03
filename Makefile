CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c ft_strchr.c ft_handlers.c ft_strlen.c ft_base.c
SRCB = ft_hashtag_bonus.c ft_base_hashtag_bonus.c ft_space_bonus.c ft_base_space_bonus.c ft_plus_bonus.c ft_base_plus_bonus.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(OBJB)
	ar -rc $(NAME) $(OBJ) $(OBJB)

bonus : $(OBJ) $(OBJB)
	ar -rc $(NAME) $(OBJ) $(OBJB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
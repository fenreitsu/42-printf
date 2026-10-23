CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = print_digit.c \
	print_str.c \
	print_char.c \
	print_mem_dir.c \
	print_evaluator.c \
	ft_printf.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f  $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = push_swap.c\
		init_stack.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR) -s

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR) -s

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
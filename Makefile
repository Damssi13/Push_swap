NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c\

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR) 

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR) 

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
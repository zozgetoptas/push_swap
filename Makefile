NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = sources/error_handling.c \
		sources/getting_positions.c \
		sources/getting_values.c \
		sources/memory_management.c \
		sources/parsing.c \
		sources/main.c \
		sources/pushing.c \
		sources/swapping.c \
		sources/reverse_rotating.c \
		sources/rotating.c \
		sources/sort_checkings.c \
		sources/easy_sorts.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
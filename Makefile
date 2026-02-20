NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

SRC = main.c main_utils.c ft_swap.c ft_simple_algo.c \
ft_rotation.c ft_ra.c ft_push.c ft_medium_algo.c \
ft_medium_algo_utilities.c ft_complex_algo.c ft_adaptive_algo.c push_swap_utilities.c compute_disorder.c \
calcul_end_index.c number_parser.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

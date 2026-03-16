CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       main_utils.c \
       adaptive_algo.c \
       simple_algo.c \
       medium_algo.c \
       medium_algo_utils.c \
       medium_chunk_sort.c \
       complex_algo.c \
       complex_algo_utils.c \
       complex_sort.c \
       parsing.c \
       parsing_utils.c \
       parsing_skip.c \
       number_parser.c \
       options_parser.c \
       options_validator.c \
       general_utils.c \
       validation.c \
       push.c \
       swap.c \
       rotation.c \
       reverse_rotation.c \
       bench.c \
       bench_swap.c \
       bench_push.c \
       bench_rotation.c \
       bench_reverse_rotation.c \
       bench_utils.c \
       ft_medium_algo_utils1.c \
       calcul_end_index.c \
       stack_in_order.c \
       hashset.c \
       hashset_utils.c

CHECKER_SRCS = checker.c \
               checker_parser.c \
               checker_utils.c \
               checker_push.c \
               checker_swap.c \
               checker_rotation.c \
               checker_rotate_reverse.c \
               checker_read_line.c \
               parsing.c \
               parsing_skip.c \
               number_parser.c \
               general_utils.c \
               validation.c \
               hashset.c \
               hashset_utils.c \
               stack_in_order.c \
               options_parser.c \
			   move_checker.c \
			   options_validator.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

NAME = push_swap
CHECKER = checker

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) $(LIBFT) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(CHECKER_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus_re : fclean bonus

.PHONY: all clean fclean re bonus bonus_re 
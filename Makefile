CC = cc
FLAGS = -Werror -Wextra -Wall  ##-g -fsanitize=address
NAME = push_swap
NAME_BONUS = checker
MAN_SRC = push_swap.c \
    functions/ft_atoi.c \
    functions/ft_split.c \
    functions/ft_strdup.c \
    functions/ft_strjoin.c \
    functions/ft_strlen.c \
    functions/ft_substr.c \
    functions/help_func.c \
    parsing.c operations.c \
    push_swap_utils.c \
    ft_free_errors.c sort_three.c \
    sort_five.c \
    indexing.c sorting.c

BOUNES_SRC = bonus/checker.c \
    bonus/functions/ft_atoi.c \
    bonus/functions/ft_split.c \
    bonus/functions/ft_strdup.c \
    bonus/functions/ft_strjoin.c \
    bonus/functions/ft_strlen.c \
    bonus/functions/ft_substr.c \
    bonus/functions/ft_strncmp.c \
    bonus/functions/help_func.c \
    bonus/parsing_bonus.c \
    bonus/operations_bonus.c \
    bonus/push_swap_utils_bonus.c \
    bonus/free_errors_bonus.c \
    bonus/get_next_line/get_next_line.c \
    bonus/get_next_line/get_next_line_utils.c

MAN_OBJ = $(MAN_SRC:.c=.o)
BOUNES_OBJ = $(BOUNES_SRC:.c=.o)

$(NAME): $(MAN_OBJ)
	@$(CC) $(FLAGS) $(MAN_OBJ) -o $(NAME)
	@echo "✅ Done"

$(NAME_BONUS): $(BOUNES_OBJ)
	@$(CC) $(FLAGS) $(BOUNES_OBJ) -o $(NAME_BONUS)
	@echo "✅ Done"

all: $(NAME)

bonus: $(NAME_BONUS)

bonus/%.o : bonus/%.c bonus/checker.h
	$(CC) $(FLAGS) -c -o $@ $<

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(MAN_OBJ) $(BOUNES_OBJ)
	# @echo "✅ Done"

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	# @echo "🧹 Cleaning up..."

re: fclean all

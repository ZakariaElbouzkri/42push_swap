
# COLORS:
CYAN = \033[0;36m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m

HEADERS =  includes/checker.h includes/libft.h includes/parser.h includes/push_swap.h includes/stack.h

PARSE_FILES = parser/args_to_stk.c parser/parse_utils.c parser/parser.c parser/split_arg.c

STACK_FILES = stack/exec_op.c stack/exec_op2.c stack/operations.c stack/operations2.c stack/utils.c stack/utils2.c stack/utils3.c

LIBFT_FILES = libft/ft_atoi.c libft/ft_atoi_long.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
	libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
	libft/ft_printf.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_puterror.c libft/ft_puthexa.c libft/ft_putnbr.c libft/ft_putnbr_fd.c \
	libft/ft_putptr.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_putunbr.c libft/ft_split.c libft/ft_strchr.c libft/ft_strchr_std.c libft/ft_strcmp.c \
	libft/ft_strcpy.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strjoin_std.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
	libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strndup.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_swap.c \
	libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c

CHECKER_FILES = bonus/checker.c bonus/execute_op.c

PS_FILES = mandatory/sort_big.c mandatory/sort_small.c mandatory/sort_stack.c mandatory/sort_utils.c mandatory/sort_utils2.c mandatory/utils.c

PS_OBJ = $(PS_FILES:.c=.o)
CHECKER_OBJ = $(CHECKER_FILES:.c=.o)
LIBFT_OBJ = $(LIBFT_FILES:.c=.o)
STACK_OBJ = $(STACK_FILES:.c=.o)
PARSE_OBJ = $(PARSE_FILES:.c=.o)

CC = cc -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

NAME = push_swap

CNAME = checker

PS_LIB = utils.a

all : $(PS_LIB) $(NAME)

$(PS_LIB) : $(LIBFT_OBJ) $(STACK_OBJ) $(PARSE_OBJ)
	${AR} $@ $^

$(NAME) : $(PS_LIB) $(PS_OBJ)
	${CC} $^ mandatory/push_swap.c -o $@

%.o : %.c $(HEADERS)
	$(CC) -o $@ -c  $<

bonus : $(CNAME)

$(CNAME) : $(PS_LIB) $(CHECKER_OBJ)
	${CC} $^ bonus/main.c -o $@

clean : 
	${RM} $(PS_OBJ) $(CHECKER_OBJ) $(LIBFT_OBJ) $(STACK_OBJ) $(PARSE_OBJ)

fclean : clean
	$(RM) $(PS_LIB) $(NAME) $(CNAME)

.PHONY : clean fclean all bonus

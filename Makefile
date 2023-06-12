NAME = push_swap
CNAME = checker
PARSER = parser
STACK = stack

CC = cc -Wall -Wextra -Werror
AR = ar -rc 
RM = rm -f 

SRC = mandatory/main.c \
	mandatory/push_swap.c \
	mandatory/sort_big.c \
	mandatory/sort_small.c \
	mandatory/sort_stack.c \
	mandatory/sort_utils.c \
	mandatory/sort_utils2.c \
	mandatory/utils.c

B_SRC = bonus/checker.c \
	bonus/exec_inst.c \
	bonus/main.c \
	bonus/utils.c

P_SRC = parser/args_to_stk.c \
	parser/parse_utils.c \
	parser/parser.c \
	parser/split_arg.c

S_SRC = stack/exec_op.c \
	stack/exec_op2.c \
	stack/operations.c \
	stack/operations2.c \
	stack/utils.c \
	stack/utils2.c \
	stack/utils3.c 

LIB_SRC = libft/ft_atoi.c libft/ft_atoi_long.c \
	libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
	libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c \
	libft/ft_memset.c libft/ft_printf.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_puterror.c \
	libft/ft_puthexa.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putptr.c libft/ft_putstr.c libft/ft_putstr_fd.c \
	libft/ft_putunbr.c libft/ft_split.c libft/ft_strchr.c libft/ft_strchr_std.c libft/ft_strcmp.c libft/ft_strcpy.c \
	libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strjoin_std.c libft/ft_strlcat.c libft/ft_strlcpy.c \
	libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strndup.c libft/ft_strnstr.c libft/ft_strrchr.c \
	libft/ft_strtrim.c libft/ft_substr.c libft/ft_swap.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c 

INCLUDES = includes/checker.h \
	includes/libft.h \
	includes/parser.h \
	includes/push_swap.h \
	includes/stack.h

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)
P_OBJ = $(P_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(P_OBJ) $(S_OBJ) $(LIB_OBJ)
	@$(CC) $^ -o $@
	@echo $@ created

bonus: $(CNAME)

$(CNAME): $(B_OBJ) $(P_OBJ) $(S_OBJ) $(LIB_OBJ)
	@$(CC) $^ -o $@
	@echo $@ created

%.o : %.c $(INCLUDES)
	@$(CC) -c $< -o $@
	@echo compiling $@ ... Done.

clean:
	@$(RM) $(OBJ) $(P_OBJ) $(S_OBJ) $(B_OBJ) $(LIB_OBJ)
	@echo "*.o files removed"

fclean: clean
	@$(RM) $(NAME) $(CNAME)
	@echo cleaned

re:fclean all

.PHONY:re all clean fclean

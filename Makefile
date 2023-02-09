HEADERS = includes/checker.h \
	includes/libft.h \
	includes/parser.h \
	includes/push_swap.h \
	includes/stack.h 

STK_FILES = stack/exec_op.c stack/exec_op2.c stack/operations.c \
	stack/operations2.c stack/utils.c stack/utils2.c stack/utils3.c 

PARSER = parser/args_to_stk.c parser/parse_utils.c \
	parser/parser.c parser/split_arg.c 

MANDATORY = mandatory/push_swap.c mandatory/sort_big.c mandatory/sort_small.c \
	mandatory/sort_stack.c mandatory/sort_utils.c mandatory/utils.c

LIB_FILES = libft/ft_atoi.c libft/ft_atoi_long.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c \
	libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_printf.c libft/ft_putchar.c  \
	libft/ft_putendl_fd.c libft/ft_puterror.c libft/ft_puthexa.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putptr.c libft/ft_putstr.c libft/ft_putstr_fd.c \
	libft/ft_strchr.c libft/ft_strchr_std.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strjoin_std.c libft/ft_strlcat.c \
	libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strndup.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c \
	libft/ft_substr.c libft/ft_swap.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c libft/ft_split.c libft/ft_putunbr.c libft/ft_putchar_fd.c

BONUS = bonus/checker.c \
	bonus/execute_op.c

# COLORS:
CYAN = \033[0;36m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m


PARSER_OBJ = $(PARSER:.c=.o)
STK_OBJ = $(STK_FILES:.c=.o)
MAN_OBJ = $(MANDATORY:.c=.o)
B_OBJ = $(BONUS:.c=.o)
LIB_OBJ = $(LIB_FILES:.c=.o)

MAIN = main.c

NAME = push_swap

BNAME = checker

LIBFT = libft.a

UTILS = utils.a

CC = cc -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
CP = cp 


all : $(LIBFT) $(NAME)

$(LIBFT) : $(LIB_OBJ)
	@$(AR) $@ $^
	@echo "${GREEN} $@ created"

$(NAME) : $(PARSER_OBJ) $(STK_OBJ) $(MAN_OBJ) $(B_OBJ) $(LIBFT) $(MAIN)
	@cc $^ -o $@
	@echo " ${GREEN}$(NAME) ${CYAN}programe created"

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c  $<

bonus : all
	@$(CP) $(NAME) $(BNAME)
	@echo "${GREEN} ${BNAME}${CYAN} programe created"

clean :
	@$(RM) $(PARSER_OBJ) $(STK_OBJ) $(MAN_OBJ) $(B_OBJ) $(LIB_OBJ)
	@echo "$(PURPLE) All object file removed "

fclean : clean
	@$(RM) $(NAME) $(BNAME) $(LIBFT)
	@echo "$(PURPLE) All created files removed"

re : fclean all
	
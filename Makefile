NAME = push_swap
BNAME = checker
LIBFT = libft.a
UTILS = utils.a
HEADERS = includes/checker.h \
	includes/libft.h \
	includes/parser.h \
	includes/push_swap.h \
	includes/stack.h 


CC = cc -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
CP = cp 

STK_FILES = stack/exec_op.c \
	stack/exec_op2.c \
	stack/operations.c \
	stack/operations2.c \
	stack/utils.c \
	stack/utils2.c \
	stack/utils3.c 

PARSER = parser/args_to_stk.c \
	parser/parse_utils.c \
	parser/parser.c \
	parser/split_arg.c 

MANDATORY = mandatory/push_swap.c \
	mandatory/sort_big.c \
	mandatory/sort_small.c \
	mandatory/sort_stack.c \
	mandatory/sort_utils.c \
	mandatory/utils.c

BONUS = bonus/checker.c \
	bonus/execute_op.c

MAIN = main.c

PARSER_OBJ = $(PARSER:.c=.o)
STK_OBJ = $(STK_FILES:.c=.o)
MAN_OBJ = $(MANDATORY:.c=.o)
B_OBJ = $(BONUS:.c=.o)

all : $(LIBFT) $(NAME)

$(LIBFT) :
	cd libft/ && make

$(NAME) : $(PARSER_OBJ) $(STK_OBJ) $(MAN_OBJ) $(B_OBJ) $(LIBFT) $(MAIN)
	@cc $^ -o $@
	@echo "$(NAME) programe created"

%.o: %.c $(HEADERS)
	$(CC) -o $@ -c  $<

bonus : all
	$(CP) $(NAME) $(BNAME)

clean :
	cd libft/ && make clean
	@$(RM) $(PARSER_OBJ) $(STK_OBJ) $(MAN_OBJ) $(B_OBJ)

fclean : clean
	cd libft/ && make fclean
	$(RM) $(NAME) $(BNAME)

re : fclean all
	
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 19:59:20 by zel-bouz          #+#    #+#              #
#    Updated: 2022/12/23 20:06:41 by zel-bouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

B_NAME = checker

LIB = pushswap.a

B_LIB = checker.a

MAIN = ./srcs/push_swap.c

B_MAIN  = ./srcs/checker.c

LIBFT = ./libft

LIBFT_LIB = $(LIBFT)/libft.a

FLAGS = -Wextra -Werror -Wall

FILES = ./srcs/ft_splite_args.c \
	./srcs/init.c \
	./srcs/linked_list_op.c \
	./srcs/ps_op.c \
	./srcs/sort_big.c \
	./srcs/sort_small.c \
	./srcs/sort_stack.c \
	./srcs/sort_utils.c \
	./srcs/stack_checks.c

B_FILES = ./srcs/ps_checker_op.c 

HEADER = ./includes/push_swap.h

OBJECT = $(FILES:.c=.o)

B_OBJ = $(B_FILES:.c=.o)


LIBFT_FILES = $(wildcard ./libft/*.c ./libft/*.h)

all: $(NAME)

$(NAME): $(LIBFT_FILES) $(OBJECT) $(HEADER) $(MAIN) $(FILES)
			@make -C $(LIBFT)
			@ar -rcs $(LIB) $(OBJECT)
			@gcc  $(FLAGS) $(MAIN) $(LIB) $(LIBFT_LIB) -o $(NAME)
			@echo "\n\033[35m Push_swap program is created .\033[0m\n"
					
bonus : $(B_NAME)

$(B_NAME): $(LIBFT_FILES) $(OBJECT) $(B_OBJ) $(HEADER) $(B_MAIN) $(FILES) $(B_FILES)
			@make -C $(LIBFT)
			@ar -rcs $(B_LIB) $(OBJECT) $(B_OBJ)
			@gcc  $(FLAGS) $(B_MAIN) $(B_LIB) $(LIBFT_LIB) -o $(B_NAME)
			@echo "\n\033[33m Checker program is created .\033[0m\n"

%.o:%.c $(HEADER)
			@gcc -c $< $(FLAGS) -o $@

clean:
			@make clean -C $(LIBFT)
			@rm -rf srcs/*.o $(LIB)
			@echo "\n\033[32mCleaning is Done!\033[0m\n"

fclean: clean
			@make fclean -C $(LIBFT)
			@rm -rf $(NAME) $(LIB) $(B_NAME) $(B_LIB)

re : fclean all
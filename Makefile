NAME = push_swap

CC = cc -Wall -Wextra -Werror 

SRC = stack/*.c parser/*.c libft/*.c mandatory/*.c

RM = rm -f

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $^ -o $@

clean:
	$(RM) $(NAME)

re: clean all


NAME = ../libft.a
HEADER = ../includes/libft.h

CC = cc -Wall -Wextra -Werror

AR = ar rc

CYAN = \033[0;36m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m

FILES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_memcpy.c ft_memmove.c ft_memchr.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_strncmp.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcmp.c ft_strlcpy.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c \
		ft_strmapi.c ft_striteri.c ft_itoa.c ft_strlcat.c ft_split.c \
		ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putunbr.c ft_putptr.c ft_putstr.c \
		get_next_line.c  ft_strjoin_std.c ft_strchr_std.c ft_strndup.c \
		ft_strcpy.c ft_strcmp.c ft_puterror.c ft_atoi_long.c ft_swap.c \


OBJECT = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	@echo "${CYAN}compiling${GREEN} ${@}" 
	@$(CC) -o $@ -c  $<

$(NAME): $(OBJECT)
	@$(AR) $@ $^
	@echo "${BLUE}libft.a${GREEN} has been created"

clean:
	@echo "${RED}Archive file removed"
	@rm -f $(OBJECT)

fclean: clean
	@echo "${RED}libft.a has been removed"
	@rm -rf $(NAME)

re: fclean all

.PHONY : clean fclean all re
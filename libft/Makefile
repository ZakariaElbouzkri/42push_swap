
NAME = libft.a

CC = cc -Wall -Wextra -Werror

AR = ar rc

FILES =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_memcpy.c ft_memmove.c ft_memchr.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_strncmp.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcmp.c ft_strlcpy.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c \
		ft_strmapi.c ft_striteri.c ft_itoa.c ft_strlcat.c ft_split.c \
		ft_printf.c ft_putchar.c ft_puthexa.c ft_putnbr.c ft_putunbr.c ft_putptr.c ft_putstr.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		get_next_line.c  ft_strjoin_std.c ft_strchr_std.c ft_strndup.c \
		ft_strcpy.c ft_strcmp.c ft_puterror.c\

OBJECT = $(FILES:.c=.o)

all: $(NAME)

%.o: %.c libft.h
	@$(CC) -o $@ -c  $<

$(NAME): $(OBJECT) libft.h
	@$(AR) $@ $^

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c ft_add_line.c ft_matlen.c ft_print_mat.c ft_is_sign_digit.c \
ft_print_mati.c ft_digitlen_in_str.c ft_strcpy.c

BONUS	= ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c \
ft_lstadd_front.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(BONUS:.c=.o)

INC	= -I includes/

LIB	= *.h

NAME	= libft.a

CC	= cc

AR	= ar rc

RM	= rm -rf

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
		$(CC) $(CFAGS) $(INC) -o $@ -c $?

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)
		ranlib $(NAME)

bonus:
		clang $(CFLAGS) -c $(SRCS) $(BONUS)
		ar rc $(NAME) *.o
		

all:		$(NAME)

clean:		
		$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

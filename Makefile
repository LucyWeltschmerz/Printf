

SRCS			= ft_treat_flags.c ft_get_string_from.c ft_strdup.c ft_print_str.c ft_printf.c ft_putchar_fd.c ft_strlen.c ft_memcpy.c ft_print_char.c ft_print_digit.c ft_strjoin.c
OBJS			= $(SRCS:.c=.o)



CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
SRCS	=	ft_printf.c

OBJS	=	$(SRCS:.c=.o)

GCC 	=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Werror -Wextra

NAME	=	libftprintf.a

.c.o:
	$(GCC) $(FLAGS) -c -I. $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			ar rcs $@ $^

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) a.out

re:			fclean all

.PHONY:		all clean fclean re
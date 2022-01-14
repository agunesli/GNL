SRCS	=	$(wildcard *.c)

SRCS_H	=	get_next_line.h

OBJS	=	$(SRCS:%.c=%.o)

NAME	=	get_next_line.a

CC		=	gcc

CFLAGS	=	-g3 -Wall -Wextra -Werror -fsanitize=address

RM		=	rm -f

all: $(NAME)

%.o:%.c  
		$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus

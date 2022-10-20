SRCS		=	push_swap.c			\
				ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c  		\
				ft_lstdelone.c 		\
				ft_lstfirst.c  		\
				ft_lstiter.c   		\
				ft_lstlast.c   		\
				ft_lstmap.c    		\
				ft_lstnew.c    		\
				ft_lstsize.c   		\
				push.c				\
				reverse_rotate.c	\
				rotate.c			\
				swap.c

OBJS		=	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C printf
			make -C libft
			$(CC) $(CFLAGS) $(OBJS) printf/libftprintf.a libft/libft.a -o $(NAME)

clean:		
			make fclean -C printf
			make fclean -C libft
			rm -f (OBJS)

fclean:		clean
			rm -f $(NAME)

.PHONY:		all clean fclean re

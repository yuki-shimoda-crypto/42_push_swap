PUSH_SWAP_SRC		=	push_swap.c			\
						check_args.c		\
						error.c				\
						push_swap.c			\
						radix_sort.c		\
						sort_stack.c		\
						sort_utils.c

LIST_SRC			=	ft_lstadd_back.c	\
						ft_lstadd_front.c	\
						ft_lstclear.c  		\
						ft_lstdelone.c 		\
						ft_lstfirst.c  		\
						ft_lstiter.c   		\
						ft_lstlast.c   		\
						ft_lstmap.c    		\
						ft_lstnew.c    		\
						ft_lstsize.c   		

OPERATION_SRC		=	push.c				\
						reverse_rotate.c	\
						rotate.c			\
						swap.c				

PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:.c=.o)
LIST_OBJ			=	$(LIST_SRC:.c=.o)
OPERATION_OBJ		=	$(OPERATION_SRC:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	push_swap

all:		$(NAME)

$(NAME):	$(PUSH_SWAP_OBJ) $(LIST_OBJ) $(OPERATION_OBJ)
			make -C printf
			make -C libft
			$(CC) $(CFLAGS) $(OBJS) printf/libftprintf.a libft/libft.a -o $(NAME)

clean:		
			make fclean -C printf
			make fclean -C libft
			rm -f $(PUSH_SWAP_OBJ) $(LIST_OBJ) $(OPERATION_OBJ)

fclean:		clean
			rm -f $(NAME)

.PHONY:		all clean fclean re

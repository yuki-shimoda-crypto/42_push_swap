# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yshimoda <yshimoda@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:53:02 by yshimoda          #+#    #+#              #
#    Updated: 2022/10/24 20:29:00 by yshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-I include

SORT_SRCS		=	src/push_swap.c			\
					src/check_args.c		\
					src/error.c				\
					src/push_swap.c			\
					src/radix_sort.c		\
					src/sort_stack.c		\
					src/is_sorted.c

LIST_SRCS		=	src/list/ft_lstadd_back.c	\
					src/list/ft_lstadd_front.c	\
					src/list/ft_lstclear.c  	\
					src/list/ft_lstdelone.c 	\
					src/list/ft_lstfirst.c 		\
					src/list/ft_lstiter.c  		\
					src/list/ft_lstlast.c  		\
					src/list/ft_lstmap.c   		\
					src/list/ft_lstnew.c   		\
					src/list/ft_lstsize.c

OP_SRCS			=	src/op/push.c			\
					src/op/reverse_rotate.c	\
					src/op/rotate.c			\
					src/op/swap.c

SRCS			=	$(SORT_SRCS) $(LIST_SRCS) $(OP_SRCS)
OBJS			=	$(SRCS:.c=.o)

LIBFTDIR		=	libft

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFTDIR)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/libft.a -o $(NAME)

%.o:%.c
			$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:		
			@$(RM) $(OBJS)
			@make fclean -C $(LIBFTDIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 22:04:28 by kferterb          #+#    #+#              #
#    Updated: 2022/03/26 22:04:29 by kferterb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	push_swap

CHECKER		=	checker

SRC			=	ft_pa_pb.c \
				ft_split.c \
				ft_utils.c \
				ft_big_sort.c \
				ft_sa_sb_ss.c \
				ft_ra_rb_rr.c \
				ft_sort_3_5.c \
				ft_check_utils.c \
				ft_lists_utils.c \
				ft_rra_rrb_rrr.c \
				ft_get_next_line.c

SRC_CHECKER	=	checker.c

SRC_PUSH	=	push_swap.c

HEADER		=	push_swap.h

OBJ			=	$(SRC_PUSH:%.c=%.o)		$(SRC:%.c=%.o)

OBJ_CHECKER	=	$(SRC_CHECKER:%.c=%.o)	$(SRC:%.c=%.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re

all			:	$(NAME)

checker		:	$(CHECKER)

$(NAME)		:	$(OBJ) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(CHECKER)	:	$(OBJ_CHECKER) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ_CHECKER) -o $(CHECKER)

%.o 		: 	%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				@rm -f $(OBJ) $(OBJ_CHECKER)

fclean		:	clean
				@$(RM) $(NAME) $(CHECKER)

re			:	fclean all

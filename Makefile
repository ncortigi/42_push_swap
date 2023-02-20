# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:42:59 by ncortigi          #+#    #+#              #
#    Updated: 2023/02/20 15:51:19 by ncortigi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC		= src/*c

OBJ		= $(SRC:.c=.o)

LIBFT	= libftt/libft.a

LIBFT_PF= libftprintf/libftprintf.a

INCLUDES= libftt/libft.a libftprintf/libftprintf.a

CC		= gcc
RM		= rm -f
CFLAGS	= -g -Wall -Wextra -Werror

$(NAME):		$(OBJ)
					make -sC libftt all
					make -sC libftprintf all
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDES)

all:			$(NAME)

clean:
				make -sC ./libftt clean
				make -sC libftprintf clean
				$(RM) $(NAME)

fclean:   clean
						$(RM) $(NAME) $(LIBFT) $(LIBFT_PF)

re:	   fclean all

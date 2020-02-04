# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseminat <tseminat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 20:04:19 by tseminat          #+#    #+#              #
#    Updated: 2019/12/08 06:00:15 by tseminat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_printf.c		\
		flags.c			\

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS_SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall

INCLUDE = -I.

LIB = libft/libft.a

NAME = ft_printf.a

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc $(NAME) $(LIB)

%.o:%.c
	gcc -c -o $@ $< $(INCLUDE)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

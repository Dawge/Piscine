# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rostroh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 15:59:34 by rostroh           #+#    #+#              #
#    Updated: 2017/01/17 16:27:20 by rostroh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h

SRC = ft_printf.c \
	  shitty_fonction.c \
	  get_base.c \
	  print.c \
	  conv.c \
	  gestion.c \
	  libft/*.c

OBJ = ft_printf.o \
	  get_base.o \
	  print.o \
	  conv.o \
	  *.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

gg:
	gcc $(SRC) main.c -I $(HEAD) libft.a

clean:
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

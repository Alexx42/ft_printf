# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 21:23:25 by ale-goff          #+#    #+#              #
#    Updated: 2018/10/06 21:34:57 by ale-goff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = basic_lists.c\
	  conversion.c\
	  flags_handle.c\
	  ft_printf.c\
	  helpers.c\
	  parse_args.c\
	  validate_fun.c\
	  wap.c

OBJ = $(SRCS=*.c=*.o)

LIB = libftprintf.a

FLAGS = -Wall -Werror -Wextra

all: $(LIB)

$(LIB): 
	gcc -c $(FLAGS) $(SRC)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(LIB)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoloshe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/15 16:54:06 by dsoloshe          #+#    #+#              #
#    Updated: 2017/06/15 16:54:08 by dsoloshe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = launcher.c funcs.c resets.c key_hooks.c setters.c mouse.c

OBJ = launcher.o funcs.o resets.o key_hooks.o setters.o mouse.o

FLAGS = -Wall -Wextra -Werror

LIBCOMP = cd libft && make && cd ..
LIBCLEAN = cd libft && make clean && cd ..
LIBFCLEAN = cd libft && make fclean && cd ..

MLGCC = gcc -o fractol -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(CDTOLIB)
	$(LIBCOMP)
	$(LIBCLEAN)
	$(CDBACK)
	$(MLGCC) $(FLAGS) $(SRC) libft/libft.a

clean:
	$(LIBCLEAN)
	rm -rf $(OBJ)

fclean:	clean
	$(LIBFCLEAN)
	rm -rf $(NAME)

re:	fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviwel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/27 09:57:05 by daviwel           #+#    #+#              #
#    Updated: 2016/09/28 09:26:13 by daviwel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAG = -Wall -Werror -Wextra

SRC_FILES = main.c \
			close_window.c \
			key_hook.c \
			draw_fractal.c \
			mouse_hook.c \
			julia.c \
			save_to_img.c \

SRC = $(addprefix srcs/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

INCLUDES = -I includes -I libft/includes

LIBRARY = -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
#	@make -C libft/ re
	@clang $(CFLAG) $(INCLUDES) -c $(SRC)
	@echo "OBJECTS COMPILED"
	@/bin/mv *.o srcs
	@clang $(CFLAG) -o $(NAME) $(OBJ) $(LIBRARY)
	@echo "PROGRAM COMPILED"

clean:
	@/bin/rm -f $(OBJ)
	@echo "OBJECTS CLEANED"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "PROGRAM CLEANED"

re: fclean all

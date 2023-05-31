# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdel-giu <gdel-giu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 09:37:55 by aperrone          #+#    #+#              #
#    Updated: 2023/05/31 12:26:26 by gdel-giu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INFO = "
# 	            _/\_/)
# 	           (),~  (
# 	   /\______///   \(
# 	 _/x       (/\    )'
# 	[_,        )==\  /
# 	  \ )_____(( (( /
# 	  |||   /// ///
# 	   ~    ~~  ~~
# \n\n"

NAME = cub3d

MAIN = main.c
INC = includes/program.h

PRGMFT = ./srcs/programft
LIBS = -L./includes -lft -llistft -lgetnextline
KIT = -L./mlx -lmlx -framework OpenGL -framework AppKit
FILES = ${wildcard $(PRGMFT)/*.c}

FLAGS = -Wall -Wextra -Werror
DEBUGGER = -g

OBJS = $(FILES:.c=.o)

CC = gcc

all: libs $(NAME)

libs: 
	make -C ./includes/.

$(NAME): $(OBJS) 
	$(CC) $(LIBS) $(OBJS) $(KIT) -o $(NAME) $(LIBS)

$(PRGMFT)/%.o : $(PRGMFT)/%.c
	$(CC) -c $(FLAGS) $< -o $@

d :
	$(CC) $(DEBUGGER) $(FLAGS) $(OBJS) $(KIT) -o $(NAME) $(LIBS)

clean:
	rm -rf $(OBJS)
	make clean -C ./includes/.

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./includes/.

re: fclean all
	
.PHONY: all clean fclean

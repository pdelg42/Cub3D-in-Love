# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 09:37:55 by aperrone          #+#    #+#              #
#    Updated: 2023/05/28 17:14:02 by sgerace          ###   ########.fr        #
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
LIBS = -L./includes -lft -llistft -lgetnextline -lfixed -lpoint -lgc
KIT = -L./mlx -lmlx -framework OpenGL -framework AppKit
FILES = ${wildcard $(PRGMFT)/*.c}

FLAGS = -g # -Wall -Wextra -Werror
DEBUGGER = -g

OBJS = $(FILES:.c=.o)

CC = gcc

all: libs $(NAME)

libs: 
	make -C ./includes/.

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) $(KIT) -o $(NAME) $(LIBS)

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

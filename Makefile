# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 09:37:55 by aperrone          #+#    #+#              #
#    Updated: 2023/05/26 14:38:06 by sgerace          ###   ########.fr        #
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

FLAGS = # -Wall -Wextra -Werror
DEBUGGER = -g

OBJS = $(FILES:.c=.o)

CC = gcc

all: libs $(NAME)

libs: 
	make -C ./includes/.

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(LIBS) $(OBJS) $(KIT) -o $(NAME) 

$(PRGMFT)/%.o : $(PRGMFT)/%.c
	$(CC) -c $(LIBS) $(FLAGS) $< -o $@

d :
	$(CC) $(DEBUGGER) $(FLAGS) $(LIBS) $(OBJS) $(KIT) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C ./includes/.

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./includes/.

re: fclean all
	
.PHONY: all clean fclean
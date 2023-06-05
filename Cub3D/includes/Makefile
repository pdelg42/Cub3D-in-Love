# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrone <aperrone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 09:29:45 by gdel-giu          #+#    #+#              #
#    Updated: 2023/06/05 15:57:00 by aperrone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
LISTFT = liblistft.a
LIBGNL = libgetnextline.a

DIR1 = ../srcs/libft
DIR2 = ../srcs/listft
DIR3 = ../srcs/get_next_line
SRCS = *.c
FSRCS1 = ${wildcard $(DIR1)/$(SRCS)}
FSRCS2 = ${wildcard $(DIR2)/$(SRCS)}
FSRCS3 = ${wildcard $(DIR3)/$(SRCS)}

OBJS1 = $(FSRCS1:.c=.o)
OBJS2 = $(FSRCS2:.c=.o)
OBJS3 = $(FSRCS3:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(LIBFT) $(LISTFT) $(LIBGNL) 

$(LIBFT): $(OBJS1)
	ar rcs $(LIBFT) $(OBJS1)

$(LISTFT): $(OBJS2)
	ar rcs $(LISTFT) $(OBJS2)

$(LIBGNL): $(OBJS3)
	ar rcs $(LIBGNL) $(OBJS3)

$(DIR1)/%.o: $(DIR1)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
	
$(DIR2)/%.o: $(DIR2)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(DIR3)/%.o: $(DIR3)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f $(OBJS3)
	
fclean: clean
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f $(OBJS3)
	rm -f $(LIBFT)
	rm -f $(LISTFT)
	rm -f $(LIBGNL)

re: fclean $(LIBFT) $(LISTFT) $(LIBGNL)

.PHONY: all clean fclean re

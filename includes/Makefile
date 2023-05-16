# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 09:29:45 by gdel-giu          #+#    #+#              #
#    Updated: 2023/05/16 19:38:54 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a
LIBFXP = libfixed.a
LISTFT = liblistft.a
LIBGNL = libgetnextline.a
LIBPNT = libpoint.a
LIBGC = libgc.a

DIR1 = ../srcs/libft
DIR2 = ../srcs/listft
DIR3 = ../srcs/get_next_line
DIR4 = ../fixed
DIR5 = ../srcs/points
DIR6 = ../srcs/gclib
SRCS = *.c
FSRCS1 = ${wildcard $(DIR1)/$(SRCS)}
FSRCS2 = ${wildcard $(DIR2)/$(SRCS)}
FSRCS3 = ${wildcard $(DIR3)/$(SRCS)}
FSRCS4 = ${wildcard $(DIR4)/$(SRCS)}
FSRCS5 = ${wildcard $(DIR5)/$(SRCS)}
FSRCS6 = ${wildcard $(DIR6)/$(SRCS)}

OBJS1 = $(FSRCS1:.c=.o)
OBJS2 = $(FSRCS2:.c=.o)
OBJS3 = $(FSRCS3:.c=.o)
OBJS4 = $(FSRCS4:.c=.o)
OBJS5 = $(FSRCS5:.c=.o)
OBJS6 = $(FSRCS6:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(LIBFT) $(LISTFT) $(LIBGNL) $(LIBFXP) $(LIBPNT) $(LIBGC)

$(LIBFT): $(OBJS1)
	ar rcs $(LIBFT) $(OBJS1)

$(LISTFT): $(OBJS2)
	ar rcs $(LISTFT) $(OBJS2)

$(LIBGNL): $(OBJS3)
	ar rcs $(LIBGNL) $(OBJS3)

$(LIBFXP): $(OBJS4)
	ar rcs $(LIBFXP) $(OBJS4)

$(LIBPNT): $(OBJS5)
	ar rcs $(LIBPNT) $(OBJS5)

$(LIBGC): $(OBJS6)
	ar rcs $(LIBGC) $(OBJS6)

$(DIR1)/%.o: $(DIR1)/%.c
	$(CC) -c $(CFLAGS) $< -o $@
	
$(DIR2)/%.o: $(DIR2)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(DIR3)/%.o: $(DIR3)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(DIR4)/%.o: $(DIR4)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(DIR5)/%.o: $(DIR5)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(DIR6)/%.o: $(DIR6)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f $(OBJS3)
	rm -f $(OBJS4)
	rm -f $(OBJS5)
	rm -f $(OBJS6)
	
fclean: clean
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f $(OBJS3)
	rm -f $(OBJS4)
	rm -f $(OBJS5)
	rm -f $(OBJS6)
	rm -f $(LIBFT)
	rm -f $(LISTFT)
	rm -f $(LIBGNL)
	rm -f $(LIBFXP)
	rm -f $(LIBPNT)
	rm -f $(LIBGC)

re: fclean $(LIBFT) $(LISTFT) $(LIBGNL) $(LIBFXP) $(LIBPNT) $(LIBGC)

.PHONY: all clean fclean re

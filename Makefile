# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 21:06:06 by rmerzak           #+#    #+#              #
#    Updated: 2021/12/29 20:26:20 by rmerzak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc 

INCLUDE = pipex.h

CFLAGS = -Wall -Wextra -Werror

sources = ft_strjoin.c ft_split.c ft_strncmp

objet = $(sources:%.c=%.o)

all: $(NAME)

# $(NAME): $(objet)
# 	ar -rcs $(NAME) $(objet)

&(NAME) : 

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	/bin/rm -rf $(objet)

fclean: clean
	/bin/rm -rf $(NAME)

re:	fclean all

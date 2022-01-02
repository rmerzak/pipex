# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 21:06:06 by rmerzak           #+#    #+#              #
#    Updated: 2022/01/02 22:44:20 by rmerzak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

sources = ft_split.c\
		ft_strjoin.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_freee.c\
		ft_strncmp.c\
		ft_substr.c\
		ft_fre.c\
		ft_pid.c ft_file.c\
		pipex.c\

all: $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(sources) -o $(NAME)

clean:
	/bin/rm -rf $(objet)

fclean: clean
	/bin/rm -rf $(NAME)

re:	fclean all

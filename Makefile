# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltran <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/23 14:18:46 by ltran             #+#    #+#              #
#    Updated: 2017/07/29 15:02:53 by ltran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRCDIR = srcs

FLAGS = -Wall -Werror -Wextra

SRCS = main.c win.c tools.c trace.c strsplit_two.c list.c err.c

F_MLX = -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit

SRC_N = $(addprefix $(SRCDIR)/, $(SRCS))

OBJDIR = objs

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

LIBFT = -L./libft/ -lft

all : $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(OBJS) $(LIBFT) $(FLAGS) -o $(NAME) $(F_MLX)

${OBJDIR}/%.o: srcs/%.c
	@mkdir -p ${OBJDIR}
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	make -C ./libft/ clean
	/bin/rm -rf $(OBJDIR)

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

##-Lminilibx_macos

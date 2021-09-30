# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 17:03:45 by mrosario          #+#    #+#              #
#    Updated: 2021/09/30 17:58:12 by mrosario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCDIR = .

GRN = \e[1;32m
RED = \e[1;31m
YEL = \e[1;33m
DEL = \e[2K\r
RST = \e[0m

SRCFILES = $(SRCDIR)/megaphone.cpp

FLAGS = -Wall -Werror -Wextra

$(NAME):
	@printf "$(YEL)Compiling program...$(RST)"
	@clang++ $(FLAGS) $(SRCFILES) -o $(NAME)
	@printf "$(DEL)$(GRN)Compiled program\n$(RST)"

all: $(NAME)

clean:
	@printf "$(YEL)Deleting program...$(RST)"
	@rm $(NAME) &>2
	@printf "$(DEL)$(GRN)Deleted program\n$(RST)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re $(NAME)
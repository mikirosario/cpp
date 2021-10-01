# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 17:03:45 by mrosario          #+#    #+#              #
#    Updated: 2021/10/01 13:44:40 by mrosario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCDIR = .

GRN = \e[1;32m
RED = \e[1;31m
YEL = \e[1;33m
DEL = \e[2K\r
RST = \e[0m

SRCFILES = $(SRCDIR)/Contact.class.cpp $(SRCDIR)/phonebook.cpp

INCLUDES = -I ./Includes

FLAGS = -Wall -Werror -Wextra

$(NAME):
	@printf "$(YEL)Compiling program...$(RST)"
	@clang++ $(FLAGS) $(INCLUDES) $(SRCFILES) -o $(NAME)
	@printf "$(DEL)$(GRN)Compiled program\n$(RST)"

all: $(NAME)

clean:
	@printf "$(YEL)Deleting program...$(RST)"
	@rm $(NAME) 2>/dev/null
	@printf "$(DEL)$(GRN)Deleted program\n$(RST)"

fclean: clean

re: fclean all

.PHONY: all clean fclean re $(NAME)
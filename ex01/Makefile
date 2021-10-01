# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 17:03:45 by mrosario          #+#    #+#              #
#    Updated: 2021/10/01 19:20:03 by mrosario         ###   ########.fr        #
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

OBJS = $(SRCFILES:.cpp=.o)

INCLUDES = -I ./Includes

FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	@printf "$(YEL)Compiling program...$(RST)"
	@clang++ $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@printf "$(DEL)$(GRN)Compiled program\n$(RST)"

$(OBJS):
	@clang++ $(FLAGS) $(INCLUDES) $(SRCFILES) -c
	
all: $(NAME)

clean:
	@printf "$(YEL)Deleting object files...$(RST)"
	@rm $(OBJS) 2>/dev/null
	@printf "$(DEL)$(GRN)Deleted object files\n$(RST)"

fclean: clean
	@printf "$(YEL)Deleting program...$(RST)"
	@rm $(NAME) 2>/dev/null
	@printf "$(DEL)$(GRN)Deleted program\n$(RST)"

re: fclean all

.PHONY: all clean fclean re $(NAME)
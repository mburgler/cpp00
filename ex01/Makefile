# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mburgler <mburgler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 11:30:56 by mburgler          #+#    #+#              #
#    Updated: 2023/12/20 11:31:25 by mburgler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := phonebook
CC         := c++
FLAGS    := -Wall -Wextra -Werror -std=c++98
 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      Contact.cpp \
                          Phonebook.cpp \
                          main.cpp \
                          
OBJS        := ${SRCS:.cpp=.o}

.cpp.o:
	${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)compiling ${CLR_RMV}${CYAN}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(BLUE)### $(GREEN)$(NAME) created $(BLUE)###${CLR_RMV}"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)deleting $(CYAN)$(NAME) $(CLR_RMV)objs "

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)deleting $(CYAN)$(NAME) $(CLR_RMV)binary"

re:			fclean all

.PHONY:		all clean fclean re



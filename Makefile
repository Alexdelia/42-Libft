# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2023/11/19 13:13:09 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
CC = 	clang
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra

# CFLAGS +=	-g3
# CFLAGS +=	-fsanitize=address

# CFLAGS +=	-Wsuggest-attribute=const
# CFLAGS +=	-Wattribute-alias=2

# CFLAGS +=	-O2

LKFLAGS =	-MMD -MP

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =			$(shell tput bold)

BLA =		$(shell tput setaf 0)
RED =		$(shell tput setaf 1)
GRE =		$(shell tput setaf 2)
YEL =		$(shell tput setaf 3)
BLU =		$(shell tput setaf 4)
MAG =		$(shell tput setaf 5)
CYA =		$(shell tput setaf 6)
WHI =		$(shell tput setaf 7)

D =			$(shell tput sgr0)
CLR =		$(shell tput el 1)

BEL =		$(shell tput bel)

PRIMARY =	$(shell tput setaf 13)
SECONDARY =	$(GRE)

PROGRESS_START =	$(PRIMARY)▐
PROGRESS_END =		$(PRIMARY)▌
# PROGRESS_EMPTY = 	-
PROGRESS_FILL =		$(SECONDARY)█

# **************************************************************************** #
#	LIBRARY	#

# LIB_PATH =	./libft/
# LIB_NAME =	$(LIB_PATH)libft.a
# LIB_INC =		-I$(LIB_PATH)inc/

# **************************************************************************** #
#	SOURCE	#

SRC_PATH =	./src/
OBJ_PATH =	./obj/
INC =		-I./inc/ #$(LIB_INC)

# SRC_NAME = ...

# SRC =		$(addprefix $(SRC_PATH), $(SRC_NAME))
SRC =		$(wildcard $(SRC_PATH)*.c) $(wildcard $(SRC_PATH)**/*.c)
SRC_NAME =	$(subst $(SRC_PATH), , $(SRC))

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ =		$(addprefix $(OBJ_PATH), $(OBJ_NAME))

# *************************************************************************** #
#	BASH	#

define	progress_bar
	@printf "$(PROGRESS_START)$(D)"
	@i=0
	@while [[ $$i -lt $(words $(SRC)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	@printf "$(D)$(PROGRESS_END)$(D)\r$(PROGRESS_START)$(D)"
endef

# *************************************************************************** #
#	RULES	#

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LKFLAGS) $(INC) -c $< -o $@
	@printf "$(D)$(PROGRESS_FILL)$(D)"

all:		launch $(NAME)
	@printf "\n$(B)$(PRIMARY)$(NAME) compiled$(D)\n"

launch:
	$(call progress_bar)

$(NAME):	$(OBJ) #$(LIB_NAME)
	$(AR) $(NAME) $(OBJ)
#	$(CC) $(CFLAGS) $(OBJ) $(LIB_NAME) -o $(NAME)
	
# $(LIB_NAME):
# 	@make -C $(LIB_PATH)
# 	@printf "$(B)$(PRIMARY)$(LIB_NAME) compiled$(D)\n"

clean:
	@$(RM) $(OBJ_PATH)
#	@make clean -C $(LIB_PATH)

fclean:		clean
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME)
#	@make fclean -C $(LIB_PATH)

re:			fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re launch

# **************************************************************************** #

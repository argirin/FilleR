# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: argirin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 17:59:49 by argirin           #+#    #+#              #
#    Updated: 2017/01/06 18:07:27 by argirin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -o
MAKE	= make -C

### EXECUTABLE ###
NAME	= argirin.filler

### INCLUDES ###
LIBFT	= libft/
OBJPATH	= objs/
INCPATH	= includes/
SRCPATH	= srcs/

### SOURCES ###
SRCS	= srcs/get_data.c\
		  srcs/solver.c\
		  srcs/free.c\
		  srcs/main.c

### OBJECTS ###
OBJS	= $(SRCS:%.c=%.o)

%.o: $(SRCPATH)%.c
	$(CC) $(FLAGS) $@ $<

### COLORS ###
C_CLEAR		= \033[2K
C_UP		= \033[A
C_NOCOLOR	= \033[0m
C_BOLD		= \033[1m
C_UNDERLINE	= \033[4m
C_BLINKING	= \033[5m
C_BLACK		= \033[1;30m
C_RED		= \033[1;31m
C_GREEN		= \033[1;32m
C_YELLOW	= \033[1;33m
C_BLUE		= \033[1;34m
C_VIOLET	= \033[1;35m
C_CYAN		= \033[1;36m
C_WHITE		= \033[1;37m

### RULES ###

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(C_YELLOW)Compiling... $(NAME) \033[0m$(C_NOCOLOR)"
	@$(MAKE) $(LIBFT) fclean && $(MAKE) $(LIBFT)
	@$(CC) $(FLAGS) $(NAME) $(OBJS) -I $(LIBFT)$(INCPATH) -L $(LIBFT) -lft
	@echo "$(C_GREEN)== $(NAME) == was successfully created$(C_NOCOLOR)"

.PHONY	:	clean fclean

clean:
	@echo "$(C_RED)Deleting object files...$(C_NOCOLOR)"
	@$(MAKE) $(LIBFT) clean
	@/bin/rm -f $(OBJS)
	@echo "$(C_GREEN)Object files were successfully deleted.$(C_NOCOLOR)"

fclean:
	@echo "$(C_RED)Deleting everything...$(C_NOCOLOR)"
	@$(MAKE) $(LIBFT) fclean
	@/bin/rm -f $(OBJS)
	@/bin/rm -f $(NAME)
	@echo "$(C_GREEN)Everything was successfully deleted.$(C_NOCOLOR)"

re		: fclean all

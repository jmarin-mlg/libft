# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 17:52:26 by jmarin-o          #+#    #+#              #
#    Updated: 2023/05/12 16:31:16 by jmarin-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus del_objects del_program clean fclean re

## PROGRAM NAME
NAME = libft.a

## DELETE ACTIONS
RM          = @rm -f
DEL_OBJECTS = $(RM) *.o
DEL_PROGRAM = $(RM) $(NAME)

## COMPILE ACTIONS (OBJECTS GENERATION)
CC             = @gcc
CFLAGS         = -c -Wall -Werror -Wextra
SOURCES        = $(filter-out $(wildcard *_bonus.c), $(wildcard *.c)) # ALL REQUIRED FUNCTIONS
SOURCES_BONUS  = $(wildcard *_bonus.c)							      # ALL BONUS FUNCTIONS
GEN_OBJS       = $(CC) $(SOURCES) $(CFLAGS)
GEN_OBJS_BONUS = $(CC) $(SOURCES_BONUS) $(CFLAGS)

## LIBRARY GENERATION
AR = @ar rcs

## MESSAGES
MSG_SPACING                 = @echo ''
MSG_READY                   = @echo "\033[92mREADY\033[0m"
MSG_READY_NOTHING_DEL       = @echo "\033[92mREADY - NOTHING TO DELETE\033[0m"
MSG_START_EXECUTION_PROGRAM = @echo '**** START EXECUTION PROGRAM LIBFT ****'
MSG_END_EXECUTION_PROGRAM   = @echo '**** END EXECUTION PROGRAM LIBFT ****'
MSG_START_EXECUTION_BONUS   = @echo '**** START EXECUTION BONUS LIBFT ****'
MSG_END_EXECUTION_BONUS     = @echo '**** END EXECUTION BONUS LIBFT ****'
MSG_START_EXECUTION_CLEAN   = @echo '**** START EXECUTION CLEAN LIBFT ****'
MSG_END_EXECUTION_CLEAN     = @echo '**** END EXECUTION CLEAN LIBFT ****'
MSG_START_EXECUTION_FCLEAN  = @echo '**** START EXECUTION FCLEAN LIBFT ****'
MSG_END_EXECUTION_FCLEAN    = @echo '**** END EXECUTION FCLEAN LIBFT ****'
MSG_START_EXECUTION_RE      = @echo '**** START EXECUTION RE LIBFT ****'
MSG_END_EXECUTION_RE        = @echo '**** END EXECUTION RE LIBFT ****'
MSG_DEL_OBJECTS             = @echo '**** DELETING OBJECTS LIBFT ****'
MSG_DEL_PROGRAM             = @echo '**** DELETING PROGRAM LIBFT ****'
MSG_START_COMPILING         = @echo '**** COMPILING, PLEASE WAIT ****'
MSG_END_COMPILING           = @echo '**** FINISHED COMPILATION ****'
MSG_GEN_OBJECTS             = @echo '**** GENERATING OBJECTS LIBFT ****'
MSG_GEN_LIBRARY             = @echo '**** GENERATING LIBRARY LIBFT ****'

all:
	$(MSG_SPACING)
	$(MSG_SPACING)
	$(MSG_START_EXECUTION_PROGRAM)
	$(MSG_SPACING)
	$(MSG_START_COMPILING)
	$(MSG_SPACING)
	$(MSG_GEN_OBJECTS)
	$(GEN_OBJS)
	$(MSG_READY)
	$(MSG_SPACING)
	$(MSG_GEN_LIBRARY)
	$(AR) $(NAME) *.o
	$(MSG_READY)
	$(MSG_SPACING)
	$(MSG_END_COMPILING)
	$(MSG_SPACING)
	$(MSG_END_EXECUTION_PROGRAM)
	$(MSG_SPACING)
	$(MSG_SPACING)

$(NAME): all

## BONUS PROGRAM
bonus:
	$(MSG_SPACING)
	$(MSG_SPACING)
	$(MSG_START_EXECUTION_BONUS)
	$(MSG_SPACING)
	$(MSG_START_COMPILING)
	$(MSG_SPACING)
	$(MSG_GEN_OBJECTS)
	$(GEN_OBJS_BONUS)
	$(MSG_READY)
	$(MSG_SPACING)
	$(MSG_GEN_LIBRARY)
	$(AR) $(NAME) *_bonus.o
	$(MSG_READY)
	$(MSG_SPACING)
	$(MSG_END_COMPILING)
	$(MSG_SPACING)
	$(MSG_END_EXECUTION_BONUS)

del_objects:
	$(MSG_DEL_OBJECTS)
ifneq ("$(wildcard *.o)", "")
	$(DEL_OBJECTS)
	$(MSG_READY)
else
	$(MSG_READY_NOTHING_DEL)
endif
	$(MSG_SPACING)

del_program:
	$(MSG_DEL_PROGRAM)
ifneq ("$(wildcard $(NAME))", "")
	$(DEL_PROGRAM)
	$(MSG_READY)
else
	$(MSG_READY_NOTHING_DEL)
endif
	$(MSG_SPACING)

clean:
	$(MSG_SPACING)
	$(MSG_SPACING)
	$(MSG_START_EXECUTION_CLEAN)
	$(MSG_SPACING)
	@make del_objects
	$(MSG_END_EXECUTION_CLEAN)
	$(MSG_SPACING)
	$(MSG_SPACING)

fclean:
	$(MSG_SPACING)
	$(MSG_SPACING)
	$(MSG_START_EXECUTION_FCLEAN)
	@make clean del_program
	$(MSG_END_EXECUTION_FCLEAN)
	$(MSG_SPACING)
	$(MSG_SPACING)

re:
	$(MSG_SPACING)
	$(MSG_SPACING)
	$(MSG_START_EXECUTION_RE)
	@make fclean $(NAME)
	$(MSG_END_EXECUTION_RE)
	$(MSG_SPACING)
	$(MSG_SPACING)

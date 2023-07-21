# env
PROGRAM = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# header
HEADER = push_swap.h

# main
SRC_M = main.c main_utils.c stdin_to_stack.c
OBJ_M = $(SRC_M:.c=.o)

# make
%.o: %.c 		$(HEADER) Makefile
						@$(CC) $(FLAGS) -c $< -o $@

(PROGRAM):		$(OBJ_M) 
					@echo "Compiling..."
					@$(CC) $(OBJ_M) -o $(PROGRAM)
					@echo "$(PROGRAM) created!"

all: $(PROGRAM)

clean:
						@$(RM) $(OBJ_M)
						@echo "Object files deleted!"

fclean:			clean
						@$(RM) $(PROGRAM)
						@echo "All deleted!"

re:				fclean all
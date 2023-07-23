# env
PROGRAM = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# header
HEADER = push_swap.h

# main
SRC_M = main.c main_utils.c stdin_to_stack.c stack_utils.c index_nbrs.c sort_utils.c sort_main.c
OBJ_M = $(SRC_M:.c=.o)

# libft
SRC_LIBFT = ft_split.c ft_substr.c ft_strlen.c ft_strdup.c
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

# make
%.o: %.c 		$(HEADER) Makefile
						@$(CC) $(FLAGS) -c $< -o $@

(PROGRAM):		$(OBJ_M) $(OBJ_LIBFT)
					@echo "Compiling..."
					@$(CC) $(OBJ_M) $(OBJ_LIBFT) -o $(PROGRAM)
					@echo "$(PROGRAM) created!"

all: $(PROGRAM)

clean:
						@$(RM) $(OBJ_M)
						@$(RM) $(OBJ_LIBFT)
						@echo "Object files deleted!"

fclean:			clean
						@$(RM) $(PROGRAM)
						@echo "All deleted!"

re:				fclean all
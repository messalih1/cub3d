NAME = cub3d
CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c   
 
 
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) libft/libft.a $^ -o $@
 

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
 
re: fclean all
	@echo "${PURPLE}re${RESET}"


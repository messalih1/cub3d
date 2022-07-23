NAME = cub3d
CC = cc
# CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c put_walls.c
 
 
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC)  -lmlx -framework OpenGL -framework AppKit  libft/libft.a  $^ -o $@
 

%.o: %.c
	@$(CC)  -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
 
re: fclean all
	@echo "${PURPLE}re${RESET}"


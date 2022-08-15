NAME = cub3d
CC = cc
CFLAGS = -g
SRC = main.c get_next_line.c put_walls.c movement_player.c finding_walls.c vertical_intersection.c horizontal_intersection.c
 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC)  $(CFLAGS) -lmlx -framework OpenGL -framework AppKit  libft/libft.a  $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	 
clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
 
re: fclean all
	@echo "${PURPLE}re${RESET}"
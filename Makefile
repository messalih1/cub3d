NAME = cub3d
CC = cc
CFLAGS = -g
SRC = main.c \
	./mandatory/moves_of_player.c \
	./mandatory/put_walls.c \
	./mandatory/find_intersections.c \
	./mandatory/horizontal_intersections.c \
	./mandatory/vertical_intersections.c \
	./mandatory/rendering_walls.c \
	./tools/get_next_line.c \
 
	
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


	
NAME		= cub3D
TEST		= cub3D_parsing

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INC			= -I. -Iinclude -Ilibft_merged/include -Iminilibx-linux

LIBFT_DIR	= libft_merged
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

PARSING		= src/parsing/check_input.c \
			  src/parsing/clean_up.c \
			  src/parsing/init.c \
			  src/parsing/parse_elements.c \
			  src/parsing/parse_map.c \
			  src/parsing/read_file.c \
			  src/parsing/utils_parsing.c \
			  src/parsing/validate_map.c \
			  src/parsing/validate_player.c \
			  src/libx/init_mlx.c \
			  src/libx/mock_start_game.c

SRCS		= src/parsing_main.c $(PARSING)
OBJ_DIR		= obj
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

parsing: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lm -o $(TEST)

$(OBJ_DIR)/%.o: %.c include/cube.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(TEST) $(LIBFT)

re: fclean all

.PHONY: all parsing clean fclean re
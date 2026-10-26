NAME	= cube3D
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# ==================== SOURCES ====================

SRCS		= $(wildcard src/*.c) main.c

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ==================== LIBFT ====================

LIBFT_DIR	= libft_merged
LIBFT		= $(LIBFT_DIR)/libft.a

# ==================== READLINE ====================

READLINE	= -lreadline

# ==================== MINILIBX ====================

MLX_DIR		= minilibx-linux/
MLX_NAME	= libmlx.a
MLX_FLAGS	= -lXext -lX11 -lm
MLX			= $(MLX_DIR)$(MLX_NAME)

# ==================== RULES ====================

all: $(NAME)

# project rule
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) $(MLX) $(MLX_FLAGS) -o $(NAME)

# Objects rule
$(OBJ_DIR)/%.o: %.c include/cube.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@ 

# libft rule
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# minilibx rule
$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test
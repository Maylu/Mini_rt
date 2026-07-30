NAME = minirt
CC = cc 

CFLAGS = -Wall -Wextra -Werror -g3 -I. -I$(LIBFT_DIR) -I$(GNL_DIR)

MLXFLAG = -lmlx -Imlx -lXext -lX11 -lm -lz
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = Includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = Includes/GNL
GNL = $(GNL_DIR)/gnl.a

SRCS = $(C_FILES)
INC = -I includes
C_FILES = minirt.c exit_functions.c init_utils.c init_struct.c add_obj.c \

OBJS = $(SRCS:.c=.o)
all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -L $(MLX_DIR) $(MLXFLAG) -o $(NAME)

%.o: %.c $(MLX_LIB)
	${CC} ${CFLAGS} -I${MLX_DIR} -O0 -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
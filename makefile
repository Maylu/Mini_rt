NAME = minirt
CC = gcc 
UNAME_S := $(shell uname -s)

MLXFLAG = -lmlx -Imlx -lXext -lX11 -lm -lz
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = Includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = Includes/GNL
GNL = $(GNL_DIR)/gnl.a

CFLAGS = -Wall -Wextra -Werror -g3 -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

ifeq ($(UNAME_S), Darwin)
    MLXFLAG = -L/opt/X11/lib -I/opt/X11/include -lmlx -lXext -lX11 -lm -lz
	CFLAGS += -I/opt/X11/include
else
    MLXFLAG = -lmlx -lXext -lX11 -lm -lz
endif

SRCS = $(C_FILES)
INC = -I includes
C_FILES = minirt.c exit_functions.c init_utils.c init_struct.c add_obj.c init_coordinate.c mlx_init.c \
		  vector_math.c intersections.c intersections_utils.c vector_math2.c camera.c utils.c add_setup.c init_struct_utils.c init_coordinate_others.c \
		  pixels.c pixels_utils.c light.c shadow.c split_charset.c color_math.c

OBJS = $(SRCS:.c=.o)
all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	find . -name 'vgcore.*' -exec rm {} \;
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -L $(MLX_DIR) $(MLXFLAG) -o $(NAME)

%.o: %.c $(MLX_LIB)
	${CC} ${CFLAGS} -I${MLX_DIR} -O0 -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_DIR)

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
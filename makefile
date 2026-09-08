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
C_FILES = Sources/Init/init_coordinate.c Sources/Init/init_coordinate_others.c Sources/Init/init_utils.c Sources/Init/init_struct.c Sources/Init/init_struct_utils.c \
			Sources/Math/vector_math.c Sources/Math/intersections.c Sources/Math/intersections_utils.c Sources/Math/vector_math2.c Sources/Math/color_math.c \
			Sources/Graphics/mlx_init.c Sources/Graphics/pixels.c Sources/Graphics/pixels_utils.c Sources/Graphics/light.c Sources/Graphics/shadow.c Sources/Graphics/camera.c \
			Sources/Miscellaneous/exit_functions.c Sources/Miscellaneous/add_obj.c Sources/Miscellaneous/split_charset.c Sources/Miscellaneous/utils.c Sources/Miscellaneous/add_setup.c \
			minirt.c

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
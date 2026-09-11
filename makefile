NAME = miniRT
BONUS = .bonus
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

INC = -I includes #pas besoin, non ?
C_FILES = Sources/Init/init_coordinate.c Sources/Init/init_coordinate_others.c Sources/Init/init_utils.c Sources/Init/init_struct.c Sources/Init/init_struct_utils.c \
			Sources/Math/vector_math.c Sources/Math/intersections.c Sources/Math/intersections_utils.c Sources/Math/vector_math2.c Sources/Math/color_math.c \
			Sources/Graphics/mlx_init.c Sources/Graphics/pixels.c Sources/Graphics/pixels_utils.c Sources/Graphics/light.c Sources/Graphics/shadow.c Sources/Graphics/camera.c \
			Sources/Miscellaneous/exit_functions.c Sources/Miscellaneous/add_obj.c Sources/Miscellaneous/split_charset.c Sources/Miscellaneous/utils.c Sources/Miscellaneous/add_setup.c \
			minirt.c

BONUS_FILES = Sources/Bonus/color_math_bonus.c Sources/Bonus/light_bonus.c Sources/Bonus/init_struct_bonus.c 

BONUS_REPLACE = Sources/Math/color_math.c Sources/Graphics/light.c Sources/Init/init_struct.c 

SRCS = $(C_FILES)

OBJS = $(SRCS:.c=.o)

MANDATORY_WITHOUT_BONUS = $(filter-out $(BONUS_REPLACE),$(C_FILES))

OBJS_BONUS = $(MANDATORY_WITHOUT_BONUS:.c=.o) $(BONUS_FILES:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	find . -name 'vgcore.*' -exec rm {} \;
#besoin de ça? 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -L $(MLX_DIR) $(MLXFLAG) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBFT) $(GNL)
	find . -name 'vgcore.*' -exec rm {} \;
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(GNL) -L $(MLX_DIR) $(MLXFLAG) -o $(NAME)
	touch $(BONUS)

%.o: %.c $(MLX_LIB)
	${CC} ${CFLAGS} -I${MLX_DIR} -O0 -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL):
	make -C $(GNL_DIR)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
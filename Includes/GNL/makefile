NAME = gnl.a
CC = cc 
AR = ar rcs

CFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(DIR_SRC), $(C_FILES))
INC = -I includes
C_FILES = get_next_line.c \
	get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^  

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

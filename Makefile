NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lmlx -framework openGL -framework AppKit

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

# MINILIBX = $(MINILIBX_DIR)libmlx.a
# MINILIBX_DIR = ./minilibx_macos/
# MINILIBX_HEADERS = $(MINILIBX_DIR)

INC_DIR = includes
SRC_DIR = src
SRC_FILES = main.c \
			parse_file.c \
			get_width_height.c \
			error.c\
			check_file.c \
			get_next_line.c \
			gnl_helpers.c \
			draw.c \
			display_info.c
			
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) 

$(LIBFT): 
	make -C $(LIBFT_DIR) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR)  fclean

re: fclean all

.PHONY: all clean fclean re

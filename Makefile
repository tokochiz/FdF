NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft -lmlx -framework openGL -framework AppKit

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/

INC_DIR = includes
SRC_DIR = src
SRC_FILES = main.c \
			check_file.c \
			error.c\
			get_width_height.c \
			get_next_line.c \
			get_next_line_utils.c \
			parse_file.c \
			fill_map.c \
			draw.c \
			key_handler.c \
			set_scale.c \
			put_img.c
			
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

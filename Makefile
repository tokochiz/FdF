NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
INC_DIR = includes

SRC_DIR = src
SRC_FILES = main.c \
			parse_file.c \
			get_w_h.c \
			error.c\
			check_file.c \
			get_next_line.c \
			
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT): 
	make -C libft 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
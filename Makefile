NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
INC_DIR = includes

SRC_DIR = src
SRC_FILES = main.c \
			
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
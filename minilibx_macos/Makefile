
#
#

NAME=libmlx.a
SRCS= mlx_shaders.c \
	mlx_new_window.m \
	mlx_init_loop.m \
	mlx_new_image.m \
	mlx_xpm.c \
	mlx_int_str_to_wordtab.c

OBJ1=$(SRCS:.c=.o)
OBJS=$(OBJ1:.m=.o)
CFLAGS+=-O2 -DGL_SILENCE_DEPRECATION

all: $(NAME)

$(NAME):	$(OBJS)
	ar -r $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(NAME) $(OBJS) *~
# rm -f mlx_app

re : fclean all

fclean : clean
	rm -f $(NAME)

.PHONY: all clean fclean re 
NAME = so_long

SRC = so_long.c \
	  ft_map.c \
	  ft_help.c \
	  ft_inits.c \
	  ft_move.c \
	  ft_display.c \
	  ft_free.c \
	  ft_path.c 

LIBDIR = lib
LIBLIB = lib/libft.a
MLXDIR = minilibx-linux/
MLXLIB = minilibx-linux/libmlx.a

OBJ = $(SRC:%.c=%.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -I. -g

MLXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(LIBLIB):
	make -sC $(LIBDIR)

$(MLXLIB):
	make -sC $(MLXDIR)

$(NAME): $(OBJ) $(LIBLIB) $(MLXLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBLIB) $(MLXLIB) $(MLXFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -sC $(LIBDIR) clean
	make -sC $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -sC $(LIBDIR) fclean
	rm -rf $(MLXLIB)

re: fclean $(NAME)

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./so_longg -I./get_next_line -I./window -I./printf -I./minilibx-linux
LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm
RM = rm -rf

SRCS =	so_longg/parse_map.c \
	so_longg/so_long.c \
	so_longg/render_map.c \
	so_longg/free_game.c \
	so_longg/launch_game.c \
	so_longg/handles.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	printf/ft_len_tab.c \
	printf/ft_printc.c \
	printf/ft_printd.c \
	printf/ft_printf.c \
	printf/ft_printp.c \
	printf/ft_prints.c \
	printf/ft_printu.c \
	printf/ft_printx.c \
	printf/ft_printxx.c

OBJS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

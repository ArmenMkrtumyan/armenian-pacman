NAME = armenian-pacman
UNAME = $(shell uname -s)

CC = cc
CFLAGS = -c -Wall -Wextra -ggdb3 -I mlx -I ft_printf# -fsanitize=address -g#-Werror

MLX = -lmlx -L mlx -framework AppKit -framework OpenGL
MLX_DIR = mlx
OBJDIR = obj

FT_PRINTF = -lftprintf -L ft_printf

SRCS = $(wildcard *.c)
TEMP = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJDIR)/, $(TEMP))

ifeq ($(UNAME), Linux)
MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_DIR = mlx_linux
CFLAGS += -D LINUX
endif

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: ftprintf mlx mkdir $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) -g -o $(NAME)

mkdir:
	@mkdir -p $(OBJDIR)

mlx:
	@cd $(MLX_DIR) && make

ftprintf:
	@cd ft_printf && make

clean:
	rm -rf $(OBJDIR)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ft_printf


clean_mlx:
	make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re ftprintf mlx mkdir

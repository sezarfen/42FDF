NAME = fdf

SRCS = check_up.c main.c utils.c draw_line.c info_page.c \
       projections.c init_colors.c read_map.c free_all.c utils2.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Werror -Wall -Wextra
MLX_FLAGS= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LIBFT= libft/libft.a
FT_PRINTF= ft_printf/libftprintf.a
MLX = minilibx_linux/libmlx.a

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	@make -C minilibx_linux

$(LIBFT):
	@echo Compiling libft..
	@make -C libft
	@echo Compilation is done!

$(FT_PRINTF):
	@echo Compiling ft_printf..
	@make -C ft_printf
	@echo Compilation is done!

clean:
	@echo Cleaning .o files
	@rm -rf *.o
	@make -C libft clean
	@make -C ft_printf clean

fclean: clean
	@echo using fclean
	@rm -rf fdf
	@make -C minilibx_linux clean

re: fclean all

.PHONY: all clean fclean re

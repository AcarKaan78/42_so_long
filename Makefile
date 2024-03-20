NAME = so_long

sources = extra_functions.c so_long_main.c control.c get_next_line_bonus.c get_next_line_utils_bonus.c map_control.c control2.c mlx_operators.c mlx_functions.c if_press_func.c itoa.c extra_controls.c

objs = extra_functions.o so_long_main.o control.o get_next_line_bonus.o get_next_line_utils_bonus.o map_control.o control2.o mlx_operators.o mlx_functions.o if_press_func.o itoa.o extra_controls.o

MLX = ./minilibx

MINILIBX_PATH = ./minilibx
MINILIBXOBJ = ./minilibx/mlx_init_loop.o ./minilibx/mlx_int_str_to_wordtab.o ./minilibx/mlx_mouse.o ./minilibx/mlx_new_image.o ./minilibx/mlx_new_window.o ./minilibx/mlx_png.o ./minilibx/mlx_shaders.o ./minilibx/mlx_xpm.o

all: $(NAME)

$(NAME):
	make mlx
	gcc -Wall -Werror -Wextra -o so_long $(sources) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx

clean:
	rm -rf $(objs)
	rm -rf $(MINILIBXOBJ)
	rm -rf ./minilibx/libmlx.a

fclean: clean
	rm -rf $(NAME)

re: fclean all

mlx:
	make -C $(MINILIBX_PATH) all
NAME		= cub3D

LIB_MLX		= Minilibx-linux/libmlx.a Minilibx-linux/libmlx_Linux.a

LIB		= Libft/libft.a

SRCS		= free_param/free_param.c \
	checks/check_elements/check_all.c checks/check_elements/check_elements.c \
	checks/check_map/check_map.c checks/check_map/check_surrounded.c checks/check_map/move_pt_2.c checks/check_map/move_pt.c \
	display/dis_background.c display/dis_hero.c display/dis_map.c \
	display/dis_walls/dis_sprite.c display/dis_walls/dis_sprite_utils_2.c display/dis_walls/dis_sprite_utils_3.c display/dis_walls/dis_sprite_utils_4.c display/dis_walls/dis_sprite_utils.c display/dis_walls/dis_walls.c display/dis_walls/dis_walls_utils.c display/dis_walls/get_texture.c \
	gameplay/move_hero.c gameplay/move_hero_utils.c \
	get_distances/get_dist_hori.c get_distances/get_dist_utils.c get_distances/get_dist_vert.c get_distances/get_dist_vert_utils.c \
	get_param_cub/get_color.c get_param_cub/get_map.c get_param_cub/get_map_utils.c get_param_cub/get_param_cub.c get_param_cub/get_resolution.c get_param_cub/get_textures.c \
	initialisation/init_hero_utils.c initialisation/init_param.c initialisation/init_param_utils.c initialisation/init_walls.c \
	save_img/ft_convert_base2.c save_img/ft_convert_base.c save_img/get_header.c save_img/get_header_utils_2.c save_img/get_header_utils_3.c save_img/get_header_utils.c save_img/get_pix.c \
	Gnl/get_next_line.c Gnl/get_next_line_utils.c \
	main.c

MLX_SRCS	= Mlx_fcts/mlx_shaders.c Mlx_fcts/mlx_new_window.m Mlx_fcts/mlx_init_loop.m Mlx_fcts/mlx_new_image.m Mlx_fcts/mlx_xpm.c Mlx_fcts/mlx_int_str_to_wordtab.c

PATH_SRCS	= srcs/

_SRCS = ${addprefix ${PATH_SRCS}, ${SRCS}}

OBJS		= $(_SRCS:.c=.o)

MLX_OBJS	= $(MLX_SRCS:.c=.o)

MLX_OBJS_M	= $(MLX_OBJS:.m=.o)

RM			= rm -rf

INC			= -I/usr/include -Imlx_linux

FLAGS			= -Wall -Wextra -Werror

MLX_FLAGS		= -lm -lX11 -lXext -FOpenGL -FAppKit

%.o: %.c
			cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

lib:
		make -C Libft

mlx_t:
		make -C Minilibx-linux
		ranlib $(LIB_MLX)

$(NAME): lib mlx_t $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIB) $(LIB_MLX) $(MLX_FLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C Libft
		make clean -C Minilibx-linux

fclean:		clean
			$(RM) $(NAME)
			make fclean -C Libft

re:			fclean all

.PHONY:		all clean fclean re

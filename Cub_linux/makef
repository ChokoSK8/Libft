#
#

NOM=libmlx.a
SRC= ../libx/*.c
SRC+= ../libx/mlx_png.c ../libx/mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
FLAGS= -Wall -Wextra -Werror
FCTS= checks/check_elements/*.c checks/check_map/*.c display/*.c display/dis_walls/*.c gameplay/*.c get_distances/*.c get_param_cub/*.c initialisation/*.c free_param/*.c ../gnl/*.c ../libft/*.c save_img/*.c  main.c
LIB=game.a
OBJ2= $(FCTS:.c=.o)

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

game:
	gcc $(FLAGS) $(FCTS) ../libx/$(NOM) -Llibmlx -L/usr/lib -lXext -lX11 -lm -lbsd -g

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all

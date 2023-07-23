#PATHS
APP=./app
BIN=./bin
SRC=./src
OBJ=./obj
LIB=./lib
LIBFT=$(LIB)/libft/bin/libft.a
INCLUDE=./include
NAME=cub3D
#FILES
MAP=map_load.c
GNL=get_next_line_utils.c get_next_line.c
MATHS=math.c vectors_d.c vectors_i.c vector_p.c
FT_UTILS=ft_utils.c
PRIMITIVES=primitives.c           #Arquivos referentes a primitivas
BASIC_GEOMETRIC= draw_rectangle.c draw_line.c draw_circle.c #Arquivos referentes a formas geometricas basicas
DRAW_UTILS=draw_utils.c

EVENTS=keyboard.c                             #Arquivos referentes a ventos de teclado mouse

CAMERA=camera.c                               #Arquivos referentes a camera
PERSONAGEM=                                   #Arquivos referentes ao personagem

LIBX=window.c image.c                         #Arquivos referentes a minilibx
ENGINE=engine.c engine_utils.c
SRCS=$(GNL) $(MATHS) $(MAP) $(DRAW_UTILS) $(FT_UTILS) $(PRIMITIVES) $(BASIC_GEOMETRIC) $(EVENTS) $(CAMERA) $(LIBX) $(ENGINE)
#VARIABLES
OBJS=$(addprefix $(OBJ)/,$(SRCS:%.c=%.o))
HEADER=-I $(INCLUDE) -I $(LIB)/libft/include
LIBS= -L $(LIB)/libft/bin -lft -lmlx -lXext -lX11 -lm
FLAGS=-Wall -Wextra -Werror -g -g3
CC=cc
VAL_FLAGS=--leak-check=full --track-origins=yes --show-leak-kinds=all -s

all: $(OBJ) $(BIN) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(HEADER) $(OBJS) $(APP)/main.c -o $(BIN)/$(NAME) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@ $(LIBS)

$(LIBFT):
	make -C $(LIB)/libft

$(OBJ):
	mkdir $@

$(BIN):
	mkdir $@

run: all
	$(BIN)/$(NAME) maps/map1.cub

check: all
	valgrind $(VAL_FLAGS) $(BIN)/$(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf $(OBJ)/*.o
	make clean -C $(LIB)/libft

fclean: clean
	rm -rf $(NAME)
#make fclean -C $(LIB)/libft

re: fclean all

.PHONY: all norm clean fclean re run check


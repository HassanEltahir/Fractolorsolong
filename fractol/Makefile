NAME = fractol


SRCS = main.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Imlx

all : $(NAME)



$(NAME):	$(OBJS)
			@make -C ./mlx
			${CC} ${CFLAGS} ${OBJS} -L./mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}


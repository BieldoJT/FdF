NAME = FdF

LIBFT = libraries/Libft/libft.a

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

MINILIBX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

MINILIBX = make_minilibx

SCRS =  main.c \
		mlx_config.c \


all: ${LIBFT} ${MINILIBX} ${NAME}


${NAME}:
		${CC} ${SCRS} ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -o ${NAME} -g
		@echo "\n${NAME} is compiled."
		@echo

${LIBFT}:
		make bonus -C libraries/Libft

make_minilibx:
		make -C minilibx-linux/

clean:
		make clean -C libraries/Libft
		make clean -C minilibx-linux/

fclean: clean
		make fclean -C libraries/Libft
		rm -rf ${NAME}

re: fclean all


.PHONY:	all clean fclean re make_minilibx

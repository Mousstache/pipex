SRCS = $(addprefix srcs/, pipex.c pipex_utils.c)

SRCS_BONUS = $(addprefix bonus/, bonus_pipex.c here_doc.c bonus_pipex_utils.c bonus_utils.c)

NAME = pipex

NAME_BONUS = pipex_bonus

INC = -Iincludes

FLAGS = -g3 -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
			cc ${FLAGS} ${INC} $(OBJS) -o $(NAME) libft.a

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all : ${NAME}

%.o:%.c
		cc ${FLAGS} ${INC}  -c $< -o $@

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${LIBFT}
		cc ${FLAGS} ${INC} ${OBJS_BONUS} -o ${NAME_BONUS} ${LIBFT}

clean :
		make -C ./libft/ clean
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -rf ${NAME} ${NAME_BONUS} ${LIBFT}
		make -C ./libft/ fclean

re : fclean all

.PHONY : all bonus clean fclean re bonus libft NAME NAME_BONUS

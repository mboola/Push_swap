CC = cc
FLAGS = -Wall -Werror -Wextra
NAME =	push_swap

SRCS	=	.
FILES	=	${SRCS}/main.c ${SRCS}/convert_arguments.c ${SRCS}/ft_split.c \
			${SRCS}/push_swap.c ${SRCS}/quick_sort.c ${SRCS}/clear_data.c \
			${SRCS}/stack_methods.c ${SRCS}/t_list_functions.c 
HEADER	=	${SRCS}/push_swap.h

# RULES

all: ${NAME}

${NAME}: ${HEADER} Makefile
	${CC} ${FLAGS} -I ${SRCS} ${FILES} -o $@ -g
	@echo "Compilation of $@ succesfull"

clean:
	@rm -f ${OBJS}
	@rm -f ${BONUS_OBJS}

fclean: clean
	@rm -f ${LIBFT}
	@rm -f ${NAME}

re: fclean all
	
.PHONY: all clean fclean re

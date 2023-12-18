# VARIABLES

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
DEBUG			=	#-g

NAME 			=	libftprintf.a

SRCS 			= 	.
HEADER 			= 	${SRCS}/ft_printf.h
FILES			=	${SRCS}/ft_conversions.c ${SRCS}/ft_putnbrbase_err.c ${SRCS}/ft_printf.c
OBJS			=	${FILES:.c=.o}

%.o: %.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -I ${SRCS} -c $< -o $@

# RULES

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs $@ ${OBJS}
	@echo "Make of $@ succesfull"

clean:
	@rm -f ${OBJS}
	@echo "clean succesfull"

fclean: clean
	@rm -f ${NAME}
	@echo "fclean succesfull"

re: fclean all
	
.PHONY: all clean fclean re

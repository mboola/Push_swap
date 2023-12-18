CC 			=	cc
FLAGS 		=	-Wall -Werror -Wextra
NAME 		=	push_swap

DEBUG		=	-g

#---FILES and their directories---
#parent dir
SRC			=	src
INCLUDES	=	include

PRINTF_SRC	=	printf
LIBFT_SRC	=	libft

#dir of operations displayed by the terminal
OPERATIONS_DIR		=	${SRC}/operations
OPERATIONS_FILES	=	${OPERATIONS_DIR}/push.c ${OPERATIONS_DIR}/reverse_rotate.c \
						${OPERATIONS_DIR}/rotate.c ${OPERATIONS_DIR}/swap.c \
						${OPERATIONS_DIR}/core_stack_methods.c

QUICK_SORT_DIR		=	${SRC}/quick_sort
QUICK_SORT_FILES	=	${QUICK_SORT_DIR}/quick_sort.c

#dir of the algorithms used to sort
SORT_ALGRTHM_DIR	=	${SRC}/sort_algorithms
SORT_ALGRTHM_FILES	=	${SORT_ALGRTHM_DIR}/sort_2.c ${SORT_ALGRTHM_DIR}/sort_3.c \
						${SORT_ALGRTHM_DIR}/sort_4.c ${SORT_ALGRTHM_DIR}/sort_5.c \
						${SORT_ALGRTHM_DIR}/sort_n.c ${SORT_ALGRTHM_DIR}/auxiliary_checks.c \
						${SORT_ALGRTHM_DIR}/push_swap.c

#dir of methods to create and clean the stacks and lists
STRCT_CREATN_DIR	=	${SRC}/struct_creation
STRCT_CREATN_FILES	=	${STRCT_CREATN_DIR}/clear_data.c ${STRCT_CREATN_DIR}/check_and_conv_arg.c \
						${STRCT_CREATN_DIR}/ft_split.c \
						${STRCT_CREATN_DIR}/stack_methods.c ${STRCT_CREATN_DIR}/t_list_functions.c \
						${STRCT_CREATN_DIR}/ptr_nodes_methods.c

#dir of main used
MAIN_DIR			=	${SRC}/main
MAIN_FILES			=	${MAIN_DIR}/main.c

ALL_FILES			=	${OPERATIONS_FILES} ${SORT_ALGRTHM_FILES} ${STRCT_CREATN_FILES} ${QUICK_SORT_FILES} ${MAIN_FILES}

HEADER				=	${INCLUDES}/push_swap.h

# RULES

all: ${NAME}

${NAME}:
	${CC} ${FLAGS} -I ${INCLUDES} ${ALL_FILES} -o $@ ${DEBUG}
	@echo "Compilation with main of $@ succesfull"

clean:

fclean: clean
	@rm -f ${NAME}

re: fclean all
	
.PHONY: all clean fclean re

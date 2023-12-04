CC 			=	cc
FLAGS 		=	
#-Wall -Werror -Wextra
NAME 		=	push_swap

DEBUG		=	-g

#---FILES and their directories---
#parent dir
SRC			=	src
INCLUDES	=	include

#dir of operations displayed by the terminal
OPERATION_DIR		=	${SRC}/operations
OPERATION_FILES		=	${OPERATION_DIR}/push.c ${OPERATION_DIR}/reverse_rotate.c \
						${OPERATION_DIR}/rotate.c ${OPERATION_DIR}/swap.c

#dir of the algorithms used to sort
SORT_ALGRTHM_DIR	=	${SRC}/sort_algorithms
SORT_ALGRTHM_FILES	=	${SORT_ALGRTHM_DIR}/sort_2.c ${SORT_ALGRTHM_DIR}/sort_3.c \
						${SORT_ALGRTHM_DIR}/sort_4.c ${SORT_ALGRTHM_DIR}/sort_5.c \
						${SORT_ALGRTHM_DIR}/sort_n.c ${SORT_ALGRTHM_DIR}/auxiliary_checks.c

#dir of methods to create and clean the stacks and lists
STRCT_CREATN_DIR	=	${SRC}/struct_creation
STRCT_CREATN_FILES	=	${STRCT_CREATN_DIR}/clear_data.c ${STRCT_CREATN_DIR}/convert_arguments.c \
						${STRCT_CREATN_DIR}/ft_split.c ${STRCT_CREATN_DIR}/push_swap.c \
						${STRCT_CREATN_DIR}/quick_sort.c ${STRCT_CREATN_DIR}/core_stack_methods.c \
						${STRCT_CREATN_DIR}/stack_methods.c ${STRCT_CREATN_DIR}/t_list_functions.c \
						${STRCT_CREATN_DIR}/ptr_nodes_methods.c

#dir of main used
MAIN_DIR			=	${SRC}/main
MAIN_FILES			=	${MAIN_DIR}/test_functions.c

ALL_FILES			=	${OPERATION_FILES} ${SORT_ALGRTHM_FILES} ${STRCT_CREATN_FILES} ${MAIN_FILES}

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

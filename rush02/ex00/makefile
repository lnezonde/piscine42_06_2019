NAME	= rush-02

RM = rm -f

SRCS = main.c print_triplet.c read_and_malloc.c fts.c cut_nb.c fill_tab.c

CFLAGS = -Wall -Werror -Wextra

${NAME}:
	cc ${CFLAGS}  ${SRCS} -o ${NAME}

all: ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

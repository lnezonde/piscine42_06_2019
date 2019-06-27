SRCS	= $(addprefix srcs/, algo.c binary_tab.c ft_tools.c main.c make_tab.c print_sol.c read_file.c valid_buf.c)

HEADER	= includes

OBJS	= ${SRCS:.c=.o}

CCF		= gcc -Wall -Wextra -Werror

NAME	= bsq

all: ${NAME}

${NAME}: ${OBJS}
	${CCF} -o ${NAME} ${OBJS}

%.o: %.c
	${CCF} -c -o $@ $< -I ${HEADER}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

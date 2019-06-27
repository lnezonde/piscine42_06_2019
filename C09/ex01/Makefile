SRCS = ${addprefix srcs/, ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c}

OBJS = ${SRCS:.c=.o}

CC = gcc -c

RM = rm -f

NAME = libft.a

HEADER = includes

CFLAGS = -Wall -Wextra -Werror

all:		${NAME}	

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

%.o: %.c	
			${CC} ${CFLAGS} -o $@ $< -I ${HEADER}	

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

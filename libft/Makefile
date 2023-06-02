NAME = libft.a 

SRC	= ft_printf.c	\
	ft_printf_utils.c	\
	ft_putnbr.c	\
	ft_putnbr_base.c \
	ft_putstr_fd.c \
	ft_itoa.c \
	ft_strdup.c \
	ft_atoi.c \
	ft_putnbr_bin.c \
	ft_strjoin.c \

OBJ = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all : ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${SRC}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

clean : 
	rm -f ${OBJ}

fclean : clean
		rm -f ${NAME} *.a

re : fclean all

.PHONY: re fclean clean bonus all

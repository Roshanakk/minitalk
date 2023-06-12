NAME_1 = server
NAME_2 = client

SRC_NAME_1 = server.c \

SRC_NAME_2 = client.c \

OBJ_NAME_1 = $(SRC_NAME_1:.c=.o)
OBJ_NAME_2 = $(SRC_NAME_2:.c=.o)

SRC_PATH 	= ./src
OBJ_PATH	= ./obj

# SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME_1) $(SRC_NAME_2))

OBJ_1 = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_1))
OBJ_2 = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_2))

CC = cc

DEBUG = -fsanitize=address,leak

CFLAGS = -g -I./include -I./libft

all : obj ${NAME_1} ${NAME_2}

obj :
	mkdir -p $(OBJ_PATH)

${NAME_1}: ${OBJ_1}
	make -C libft
	$(CC) $(OBJ_1) -o $(NAME_1) ./libft/libft.a

${NAME_2}: ${OBJ_2}
	make -C libft
	$(CC) $(OBJ_2) -o $(NAME_2) ./libft/libft.a

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	${CC} ${CFLAGS} -c $< -o $@

# $(OBJ_PATH_2)/%.o:$(SRC_PATH_2)/%.c
# 	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBJ_PATH}
	make -C libft clean

fclean : clean
		rm -f ${NAME_1} ${NAME_2} *.a
		make -C libft fclean

re : fclean all

.PHONY: re fclean clean all
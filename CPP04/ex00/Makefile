NAME = Animal

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp

RM = rm -rf

all : ${NAME}

${NAME} : ${SRC}
	${CC} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	${RM} ${NAME}

re : clean all

.PHONY : all re clean
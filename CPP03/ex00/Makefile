NAME = ClapTrap

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp ClapTrap.cpp

all : ${NAME}

${NAME} :
	${CC} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	rm -rf ${NAME}

re: clean all

.PHONEY: clean re all
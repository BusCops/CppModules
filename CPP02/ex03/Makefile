NAME = Fixed

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp point.cpp bsp.cpp

all : ${NAME}

${NAME} :
	${CPP} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	rm -rf ${NAME}

re : clean all

.PHONEY : clean all re
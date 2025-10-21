NAME = HARL

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Harl.cpp

all : ${NAME}

${NAME} :
	${CPP} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	rm -rf ${NAME}

re : clean all

.PHONEY : clean all re
NAME = account

CC = c++

CPPFLAGS =  -std=c++98

SRC = tests.cpp Account.cpp

all : ${NAME}

${NAME} :
	${CC} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	rm ${NAME}

re : clean all

.PHONEY : all clean
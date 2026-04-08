NAME = Array
CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp

TPP = Array.tpp

RM = rm -rf

all: ${NAME}

${NAME} : ${SRC} ${TPP}

	${CPP} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :

	${RM} ${NAME}

re : clean all

PHONY : all clean re
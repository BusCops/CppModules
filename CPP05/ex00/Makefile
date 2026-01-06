NAME = Bureaucrat

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp main.cpp

RM = rm -rf

all: ${NAME}

${NAME} : ${SRC}

	${CPP} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :

	${RM} ${NAME}

re : clean all

PHONY : all clean re
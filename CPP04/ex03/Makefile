NAME = AMateria

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AMateria.cpp Concrete.cpp ICharacter.cpp main.cpp

RM = rm -rf

all : ${NAME}

${NAME} : ${SRC}
	${CC} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	${RM} ${NAME}

re : clean all

.PHONY : all re clean
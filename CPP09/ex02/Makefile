NAME = PmergeMe

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

TPP = PmergeMe.tpp

HEADER = PmergeMe.hpp

RM = rm -rf

all: ${NAME}

${NAME} : ${OBJ} ${HEADER} ${TPP}
	${CPP} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

PHONY : all clean re
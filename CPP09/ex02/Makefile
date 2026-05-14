NAME = PmergeMe

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -rf

all: ${NAME}

${NAME} : ${OBJ}
	${CPP} ${CPPFLAGS} ${OBJ} -o ${NAME}

main.o: main.cpp PmergeMe.hpp PmergeMe.tpp
	${CPP} ${CPPFLAGS} -c $< -o $@

PmergeMe.o: PmergeMe.cpp PmergeMe.hpp PmergeMe.tpp
	${CPP} ${CPPFLAGS} -c $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

PHONY : all clean re
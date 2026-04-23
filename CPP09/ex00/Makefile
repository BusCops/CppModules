NAME = btc

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = BitcoinExchange.hpp
RM = rm -rf

all: ${NAME}

${NAME} : ${OBJ} ${HEADER}
	${CPP} ${CPPFLAGS} ${OBJ} -o ${NAME}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

PHONY : all clean re
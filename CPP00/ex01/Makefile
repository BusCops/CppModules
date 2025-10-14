NAME = PhoneBook

CC = c++

CPPFLAGS = -Wall -Werror -Wextra

SRC = main.cpp Contact.cpp PhoneBook.cpp

all : ${NAME}

${NAME} :
	${CC} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :
	rm ${NAME}

re : clean all

.PHONY : all clean
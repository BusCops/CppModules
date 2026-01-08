NAME = Bureaucrat

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp main.cpp Intern.cpp

RM = rm -rf

all: ${NAME}

${NAME} : ${SRC}

	${CPP} ${CPPFLAGS} ${SRC} -o ${NAME}

clean :

	${RM} ${NAME}

re : clean all

PHONY : all clean re
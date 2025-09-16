NAME = megaphone

CC = c++

CPPFLAGS = -Wall -Werror -Wextra

SRC = megaphone.cpp

all : ${NAME}

$(NAME) :
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

re : clean all

.PHONY : all clean
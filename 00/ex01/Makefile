NAME =		phonebook

INCLUDES =	PhoneBook.hpp \
			Contact.hpp

SRC =		PhoneBook.cpp \
			Contact.cpp \
			main.cpp


all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.

NAME = account

INCLUDES =	Account.hpp

SRC =		Account.cpp \
			tests.cpp

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC) -o $(NAME) -I.

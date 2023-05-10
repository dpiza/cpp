NAME =		form

INCLUDES =	Bureaucrat.hpp \
			Form.hpp

SRC =		Bureaucrat.cpp \
			Form.cpp \
			main.cpp

COMP = clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.
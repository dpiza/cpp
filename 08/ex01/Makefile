NAME =		ex01

INCLUDES =	Span.hpp

SRC =		Span.cpp \
			main.cpp

COMP = clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.
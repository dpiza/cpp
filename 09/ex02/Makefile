NAME	= PmergeMe

HEADERS	=	PmergeMe.hpp \
			Sort.tpp

SRC		=	main.cpp \
			PmergeMe.cpp

RM		= rm -rf
COMP	= clang++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	$(COMP) $(CFLAGS) $(SRC) -o $(NAME) -I.

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all
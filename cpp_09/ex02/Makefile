SRCS_NAME = PmergeMe main

SRCS = $(SRCS_NAME:=.cpp)

OBJECTS = $(SRCS:.cpp=.o)

NAME = PmergeMe

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

CC = c++

all: $(NAME)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

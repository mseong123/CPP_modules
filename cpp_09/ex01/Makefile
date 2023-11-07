SRCS_NAME = RPN main

SRCS = $(SRCS_NAME:=.cpp)

OBJECTS = $(SRCS:.cpp=.o)

NAME = RPN

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

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

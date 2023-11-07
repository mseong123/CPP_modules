SRCS_NAME = main ClapTrap ScavTrap FragTrap DiamondTrap

SRCS = $(SRCS_NAME:=.cpp)

OBJECTS = $(SRCS:.cpp=.o)

NAME = diamondtrap

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow

CC = c++

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

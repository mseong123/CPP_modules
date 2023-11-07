#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "Please enter correct amount of arguments. Program terminating"<< std::endl;
		return (0);
	}
	ScalarConverter::convert(std::string(argv[1]));
	
	
}
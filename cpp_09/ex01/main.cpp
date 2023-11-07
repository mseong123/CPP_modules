#include "RPN.hpp"

int	main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cout << "Error: Require 1 argument." <<std::endl;
		return (0);
	}
	else {
		RPN rpn;
		rpn.parse_input(std::string(argv[1]));
	}
	return (0);

	

	
	
}
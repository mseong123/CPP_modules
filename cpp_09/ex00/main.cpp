#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	
	if (argc == 1) {
		std::cout << "Error: could not open file." <<std::endl;
		return (0);
	}
	else if (argc > 2){
		std::cout << "Error: more than 1 argument provided." <<std::endl;
		return (0);
	}
	else {
		std::fstream input(std::string(argv[1]), std::fstream::in);
		if (!input.is_open()) {
			std::cout << "Error: could not open file." <<std::endl;
			return (0);
		}
		BitcoinExchange btc;
		try {
			btc.read_data("data.csv");
		}
		catch (std::exception & e) {
			std::cout << "Exception caught: Missing or invalid data.csv file" << std::endl;
		}
		try {
			btc.parse_input(input);
		}
		catch (std::exception & e) {
			std::cout << "Exception caught: First line of input line should be 'date | value'" << std::endl;
		}
	}
	return (0);

	

	
	
}
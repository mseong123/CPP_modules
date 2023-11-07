#include "Harl.hpp"

int	find_str_index(char *str)
{
	std::string filter(str);
	std::string arg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4)
	{
		if (filter == arg[i])
			return (i);
		i++;
	}
	return (-1);
}

int main(int argc, char **argv)
{
	Harl harl;
	int	index;

	if (argc == 2)
	{
		index = find_str_index(argv[1]);
		switch (index) {
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				harl.complain("DEBUG");
				std::cout << std::endl;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				harl.complain("INFO");
				std::cout << std::endl;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				harl.complain("WARNING");
				std::cout << std::endl;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				harl.complain("ERROR");
				std::cout << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	return (0);
}
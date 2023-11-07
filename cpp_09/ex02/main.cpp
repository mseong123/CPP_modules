#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	
	if (argc < 2) {
		std::cout << "Error: Require at least 1 argument." <<std::endl;
		return (0);
	}
	else {
		PmergeMe pm;
		try {
			//parse through input to check for errors. If incorrect input throw InputErrorException.Timestamp for sort operation not counted yet.
			pm.parse_input(argc, argv);
			//separate timestamp for sort operation recorded in functions below
			pm.sort_vec(argc, argv);
			pm.sort_list(argc, argv);
			//comparing results of sort using different containers, if different result throw ResultErrorException;
			pm.compare_results(pm.get_list());
			std::cout << "After: " << pm.get_vec();
			std::cout << std::endl;
			std::cout << "Time to process a range of " << pm.get_vec().size() << " elements with std::vector: " << pm.get_time_vec() << " us" << std::endl;
			std::cout << "Time to process a range of " << pm.get_list().size() << " elements with std::list: " << pm.get_time_list() << " us" << std::endl;
		}
		catch (PmergeMe::InputErrorException & e){
			std::cout << e.what() << std::endl;
		}
		catch (PmergeMe::ResultErrorException & e){
			std::cout << e.what() << std::endl;
		}
	}
	return (0);

	

	
	
}
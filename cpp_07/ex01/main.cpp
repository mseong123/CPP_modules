#include "iter.hpp"

int	main(void) {
	std::string	arrString[3] = {"hello", "goodbye", "see you"};
	int			arrInt[3] = {120, 456, 789};
	bool		arrBool[3] = {false, true, false};

	iter<std::string>(arrString, 3, printElement<std::string>);
	//can do the below too for printElement, compiler will use template argument deduction to guess the type.
	iter<int>(arrInt, 3, printElement);
	iter<bool>(arrBool, 3, printElement);
	return (0);
}
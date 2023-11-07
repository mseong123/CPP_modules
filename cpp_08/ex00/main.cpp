#include "easyfind.hpp"
#include <list>
#include <vector>
#include <array>

int	main(void) {
	std::cout << BLUE << "Testing with Array container" << DEFAULT << std::endl;
	std::array<int, 10> arr;
	std::cout << GREEN << "Assigning 10 values to Array container" << DEFAULT << std::endl;
	int i = 0;
	while (i < 10)
	{
		arr[i] = i + 1;
		i++;
	}
	std::cout << GREEN << "Displaying Array container values" << DEFAULT << std::endl;
	for (std::array<int, 10>::const_iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Testing with easyfind function with integer value of 15" << DEFAULT << std::endl;
	try {
		std::array<int, 10>::iterator it = easyfind<std::array<int, 10> >(arr, 15);
		std::cout << "Found first intance of parameter in container: " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception thrown: value not found in container"<< std::endl;
	}
	std::cout << GREEN << "Testing with easyfind function with integer value of 5" << DEFAULT << std::endl;
	try {
		std::array<int, 10>::iterator it = easyfind<std::array<int, 10> >(arr, 5);
		std::cout << "Found first intance of parameter in container: " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception: value not found in container"<< std::endl;
	}
	std::cout << "-------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "Testing with Vector container using same values as Array container" << DEFAULT << std::endl;
	std::vector<int> vec(arr.begin(), arr.end());
	std::cout << GREEN << "Displaying Vector container values" << DEFAULT << std::endl;
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Testing with easyfind function with integer value of 20" << DEFAULT << std::endl;
	try {
		std::vector<int>::iterator it = easyfind<std::vector<int> >(vec, 20);
		std::cout << "Found first intance of parameter in container: " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception thrown: value not found in container"<< std::endl;
	}
	std::cout << "-------------------------------------------------------------" << std::endl;

	std::cout << BLUE << "Testing with List container" << DEFAULT << std::endl;
	std::list<int> mylist;
	mylist.assign(arr.begin(), arr.end());
	std::cout << GREEN << "Displaying List container values" << DEFAULT << std::endl;
	for (std::list<int>::const_iterator it = mylist.begin(); it != mylist.end(); it++)
		std::cout << *it << std::endl;
	std::cout << GREEN << "Testing with easyfind function with integer value of 3" << DEFAULT << std::endl;
	try {
		std::list<int>::iterator it = easyfind<std::list<int> >(mylist, 3);
		std::cout << "Found first intance of parameter in container: " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception thrown: value not found in container"<< std::endl;
	}


	return (0);
}
#include "Array.hpp"
/*
class myClass {
		public:
			myClass(void) : _name("default") {
			}
			myClass(std::string name) : _name(name) {
			}
			std::string getName() const {
				return this->_name;
			}
		private:
			std::string _name;
};

std::ostream & operator<<(std::ostream & o, myClass & src)
{
	return o << src.getName();
}
*/

int	main(void) {
	std::cout << GREEN << "Testing Instantialization of Array Class Templates with different simple types" << DEFAULT << std::endl;
	Array<int> myIntArray(5);
	Array<std::string> myStringArray(3);
	Array<double> myDoubleArray(6);
	

	myIntArray[3] = 56;
	myStringArray[0] = "Hello";
	myDoubleArray[2] = 22.23;
	std::cout << BLUE << "Displaying all elements of myIntArray(5)" << DEFAULT << std::endl;
	std::cout << myIntArray;
	std::cout << BLUE << "Displaying all elements of myStringArray(3)" << DEFAULT << std::endl;
	std::cout << myStringArray;
	std::cout << BLUE << "Displaying all elements of myDoubleArray(6)" << DEFAULT << std::endl;
	std::cout << myDoubleArray;
	std::cout << std::endl;

	std::cout << GREEN << "TESTING COPY AND ASSIGNMENT OPERATOR" << DEFAULT << std::endl;
	std::cout << BLUE << "Creating copy of myIntArray(5) and testing copy is the same" << DEFAULT << std::endl;
	Array<int> myIntArray_copy_one(myIntArray);
	std::cout << myIntArray_copy_one;
	std::cout << BLUE << "Testing copy assignment operator for myIntArray(5)" << DEFAULT << std::endl;
	Array<int> myIntArray_copy_two;
	myIntArray_copy_two = myIntArray;
	std::cout << myIntArray_copy_one;
	std::cout << std::endl;

	std::cout << GREEN << "Testing to access out of bounds array index" << DEFAULT << std::endl;
	std::cout << BLUE<< "Testing index 5 for myIntArray(5)" << DEFAULT << std::endl;
	try {
		std::cout << myIntArray[5] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error:Out of bound. Exception caught" << std::endl;
	}
	std::cout << BLUE<< "Testing index -1 for myStringArray(-1)" << DEFAULT << std::endl;
	try {
		std::cout << myStringArray[-1] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error:Out of bound. Exception caught" << std::endl;
	}
	std::cout << std::endl;
/*
	std::cout << GREEN << "Testing Instantialization of Array Class Templates with complex CLASS type" << DEFAULT << std::endl;
	Array<myClass> myClassArray(5);
	std::cout << myClassArray;
	std::cout << BLUE<< "Accessing array of myClass and writing to it" << DEFAULT << std::endl;
	myClass myClassSecond("mseong");
	myClassArray[2] = myClassSecond;
	std::cout << myClassArray;
	std::cout << std::endl;
*/
	std::cout << GREEN << "TESTING FOR EMPTY ARRAY" << DEFAULT << std::endl;
	std::cout << BLUE<< "Creating emptyArrayOne and emptyArrayTwo" << DEFAULT << std::endl;
	Array<int> emptyArrayOne;
	Array<int> emptyArrayTwo(0);
	std::cout << emptyArrayOne;
	std::cout << emptyArrayTwo;
	std::cout << BLUE<< "Attempting to access empty arrays " << DEFAULT << std::endl;
	try {
		std::cout << emptyArrayOne[5] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error:Empty array. Exception caught" << std::endl;
	}
	try {
		std::cout << emptyArrayTwo[0] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error:Empty array. Exception caught" << std::endl;
	}
	std::cout << std::endl;

	std::cout << GREEN << "TESTING FOR CONST ARRAY" << DEFAULT << std::endl;
	std::cout << BLUE<< "Creating constArray(5) and reading from it" << DEFAULT << std::endl;
	const Array<int> constArray(5);
	std::cout << constArray;
	/*
	std::cout << BLUE<< "Attempting to write to constArray(5)" << DEFAULT << std::endl;
	constArray[2] = 3;
	*/
	std::cout << std::endl;
	//system("leaks main");
	return (0);
}
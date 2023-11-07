#include "Serializer.hpp"

int	main(void) {
	Data A;
	A.number = 5;

	std::cout << "Testing reinterpret_cast using static class Serializer" << std::endl;
	std::cout << "Memory address of Data structure A: " << &A << std::endl;
	std::cout << "Memory address after serializing and deserializing: " << Serializer::deserialize(Serializer::serialize(&A)) << std::endl;

	std::cout << "Testing usage of struct Data" << std::endl;
	std::cout << "A.number = " << A.number << std::endl;
	return (0);
}
#include "Span.hpp"

int	main(void) {
	std::cout << BLUE << "Subject PDF Test" << DEFAULT << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << BLUE << "Additional Tests" << DEFAULT << std::endl;
	std::cout << GREEN << "Adding numbers exceeding initial size of 5" << DEFAULT << std::endl;
	try {
		sp.addNumber(15);
	}
	catch (Span::MaxSizeException & e) {
		std::cout << "Exception caught, max size exceeded" <<std::endl;
	}
	std::cout << GREEN << "Using longest span and shortest span with only 1 number inside class" << DEFAULT << std::endl;
	Span sp1 = Span(5);
	sp1.addNumber(6);
	std::cout << sp1;
	try {
		sp1.longestSpan();
	}
	catch (Span::InsufficientElementException & e) {
		std::cout << "Exception caught, can't calculate longest span because only 1 number inside class" <<std::endl;
	}
	try {
		sp1.shortestSpan();
	}
	catch (Span::InsufficientElementException & e) {
		std::cout << "Exception caught, can't calculate shortest span because only 1 number inside class" <<std::endl;
	}
	std::cout << GREEN << "Testing Span with 10,000 numbers" << DEFAULT << std::endl;
	Span sp2 = Span(10000);
	int i = 0;
	while (i < 10000) {
		sp2.addNumber(i++);
	}
	// std::cout << sp2;
	std::cout << GREEN << "Using Iterators to addNumbers" << DEFAULT << std::endl;
	Span sp3 = Span(10000);
	std::vector<int> vec = sp2.get_vec();
	std::vector<int>::iterator begin = vec.begin();
	std::vector<int>::iterator end = vec.end();
	sp3.addNumber(begin, end);
	// std::cout << sp3;
	
	return (0);
}
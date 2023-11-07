#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p) {
	try {
		A & a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e)
	{
	}
	try {
		B & b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception & e)
	{
	}
	try {
		C & c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception & e)
	{
	}
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

Base * generate(void) {
	int random = rand();
	if (random % 3 == 0)
		return new A();
	else if (random % 3 == 1)
		return new B();
	else
		return new C();
}

int	main(void) {
	std::cout << "Generate 4 random classes (A,B or C)" << std::endl;
	Base *b1 = generate();
	Base *b2 = generate();
	Base *b3 = generate();
	Base *b4 = generate();

	std::cout << "Testing actual type of Object pointed by *b1" << std::endl;
	identify(b1);
	identify(*b1);

	std::cout << "Testing actual type of Object pointed by *b2" << std::endl;
	identify(b2);
	identify(*b2);

	std::cout << "Testing actual type of Object pointed by *b3" << std::endl;
	identify(b3);
	identify(*b3);

	std::cout << "Testing actual type of Object pointed by *b4" << std::endl;
	identify(b4);
	identify(*b4);

	delete b1;
	delete b2;
	delete b3;
	delete b4;
	system("leaks main");
	return (0);
}
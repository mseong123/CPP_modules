#include "MutantStack.hpp"
#include <list>

int	main(void) {
	std::cout << BLUE << "Subject PDF Test" << DEFAULT << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << GREEN << "Displaying mstack elements" << DEFAULT << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << BLUE << "Testing with copy constructor and copy assignment operators for MutantStack" << DEFAULT << std::endl;
	MutantStack<int> mstack1(mstack);
	std::cout << GREEN << "Displaying mstack1 elements" << DEFAULT << std::endl;
	std::cout << mstack1;
	MutantStack<int> mstack2 = mstack;
	std::cout << GREEN << "Displaying mstack2 elements" << DEFAULT << std::endl;
	std::cout << mstack2;

	std::cout << BLUE << "Testing with List container using Subject PDF Test" << DEFAULT << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it_list = mlist.begin();
	std::list<int>::iterator ite_list = mlist.end();
	++it_list;
	--it_list;
	std::cout << GREEN << "Displaying mlist elements" << DEFAULT << std::endl;
	while (it_list != ite_list)
	{
	std::cout << *it_list << std::endl;
	++it_list;
	}
	
	return (0);
}
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <algorithm>
# include <exception>
# include <stack>
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define DEFAULT "\033[0m"


template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack & src);
		MutantStack & operator=(const MutantStack & src);
		//changing alias of class iterator type in underlying container. 
		//Can't create a MutantStack class iterator and inheriting from std::stack<T>::container_type::iterator as return type of begin/end
		// function types below can't reconcile to the class as per compiler. 
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end()const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

template<typename T>
MutantStack<T>::MutantStack() {
}

template<typename T>
MutantStack<T>::~MutantStack() {
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack & src) : std::stack<T>(src) {
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack & src) {
	if (this != & src)
	{
		std::stack<T>::operator=(src);
	}
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	//can't use std::stack<T>::container_type::iterator.begin()
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return std::stack<T>::c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return std::stack<T>::c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return std::stack<T>::c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const{
	return std::stack<T>::c.rend();
}


template<typename T>
std::ostream & operator<<(std::ostream & o, MutantStack<T> & src){
	int i = 0;
	typename MutantStack<T>::iterator it = src.begin();
	typename MutantStack<T>::iterator ite = src.end();
	for (; it != ite; it++)
	{
		o << *it <<std::endl;
	}
	return o;
}

#endif

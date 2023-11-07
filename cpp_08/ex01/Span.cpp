#include "Span.hpp"

Span::Span(void): _size(0) {
}

Span::~Span(void) {
}

Span::Span(unsigned int n) : _size(n) {
	
}

Span::Span(Span const & src) {
	std::cout << "here" <<std::endl;
	*this = src;
}

Span & Span::operator=(Span const & src) {
	
	if (this != &src) {
		this->_vec = src.get_vec();
		this->_size = src.get_size();
	}
	return *this;
}

std::vector<int> Span::get_vec(void) const {
	return this->_vec;
}

unsigned int Span::get_size(void) const {
	return this->_size;
}

void	Span::addNumber(int n) {
	if (this->_size == this->_vec.size())
		throw Span::MaxSizeException();
	else {
		this->_vec.push_back(n);
	}
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + this->_vec.size() > this->_size)
		throw Span::MaxSizeException();
	else {
		this->_vec.insert(this->_vec.end(), begin, end);
	}
}

const char *Span::MaxSizeException::what() const throw() {
	return "Max Size exceeded. Can't add anymore integers.";
}

const char *Span::InsufficientElementException::what() const throw() {
	return "Insufficient Elements. Can't return span";
}

int Span::shortestSpan() const {
	if (this->_vec.size() < 2)
		throw Span::InsufficientElementException();
	else {
		std::vector<int>::const_iterator it1 = this->_vec.begin();
		std::vector<int>::const_iterator it2 = this->_vec.begin();
		it2++;
		int diff = *it2 - *it1 < 0? -(*it2 - *it1) : (*it2 - *it1);
		int shortest = diff;
		while (it2 != this->_vec.end())
		{
			diff = *it2 - *it1 < 0? -(*it2 - *it1) : (*it2 - *it1);
			if (diff < shortest)
				shortest = diff;
			it1++;
			it2++;
		}
		return (shortest);
	}
}

int Span::longestSpan() const {
	if (this->_vec.size() < 2)
		throw Span::InsufficientElementException();
	else {
		std::vector<int>::const_iterator it1 = this->_vec.begin();
		std::vector<int>::const_iterator it2 = this->_vec.end();
		int min_element = *std::min_element(it1, it2);
		int max_element = *std::max_element(it1, it2);
		return (max_element - min_element);
	}
}

std::ostream & operator<<(std::ostream & o, Span & src) {
	std::vector<int>::const_iterator it;
	for (it = src.get_vec().begin(); it != src.get_vec().end(); it++) {
		o << *it << std::endl;
	}
	return o;
}
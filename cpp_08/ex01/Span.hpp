#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <array>
# include <list>
# include <iterator>
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define DEFAULT "\033[0m"

class Span {
	private:
		std::vector<int> _vec;
		unsigned int _size;
	public:
		Span(void);
		~Span(void);
		Span(unsigned int n);
		Span(Span const & src);
		Span & operator=(Span const & src);
		std::vector<int> get_vec(void) const;
		unsigned int get_size(void) const;
		void addNumber(int n);
		void addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
		class MaxSizeException: public std::exception {
			public:
				const char *what() const throw();
		};
		class InsufficientElementException: public std::exception {
			public:
				const char *what() const throw();
		};
		int shortestSpan() const;
		int longestSpan() const;
};

std::ostream & operator<<(std::ostream & o, Span & src);

#endif

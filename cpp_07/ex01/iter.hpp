#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename T>
void	printElement(T const & element) {
	std::cout << element << std::endl;
}

template<typename T>
void	iter(T * array, int length, void(*f)(T const &)) {
	int i = 0;
	while (i < length)
		f(array[i++]);
}

#endif

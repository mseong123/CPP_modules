#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <exception>
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define DEFAULT "\033[0m"

template<typename T>
typename T::iterator	easyfind(T & container, int i) {
	typename T::iterator ptr;

	ptr = std::find(container.begin(), container.end(), i);
	if (ptr == container.end())
		throw std::exception();
	else
		return ptr;
}

#endif

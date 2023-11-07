#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<typename T>
void	swap(T & swap1, T & swap2) {
	T temp = swap1;
	swap1 = swap2;
	swap2 = temp;
}

template<typename T>
T	min(T min1, T min2) {
	return (min1 < min2 ? min1: min2);
}

template<typename T>
T	max(T max1, T max2) {
	return (max1 > max2 ? max1: max2);
}

#endif

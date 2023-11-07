#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define DEFAULT "\033[0m"

template< typename T >
class Array {
	public:
		Array< T >(void);
		Array< T >(unsigned int n);
		Array< T >(Array < T > & src);
		Array< T > & operator=(Array < T > & src);
		int size() const;
		T & operator[](unsigned int i);
		T operator[](unsigned int i) const;
		~Array(void);
	private:
		T *_array;
		unsigned int _size;
};

template <typename T>
Array< T >::Array(void) {
	this->_array = NULL;
	this->_size = 0;
}

template <typename T>
Array< T >::Array(unsigned int n) {
	this->_array = new T[n];
	this->_size = n;
}

template <typename T>
Array< T >::~Array(void) {
	if (this->_array)
		delete [] this->_array;
}

template <typename T>
Array< T >::Array(Array< T > & src) {
	*this = src;
}

template <typename T>
Array< T > & Array< T >::operator=(Array< T > & src) {
	if (this != &src)
	{
		int i = 0;
		this->_size = src.size();
		if (this->_array)
			delete [] this->_array;
		this->_array = new T[this->_size];
		while (i < this->_size)
		{
			this->_array[i] = src[i];
			i++;
		}
	}
	return *this;
}

template <typename T>
int Array< T >::size() const{
	return this->_size;
}


template <typename T>
T & Array< T >::operator[](unsigned int i) {
	if (this->_size == 0 || i < 0 || i > this->_size - 1)
		throw std::exception();
	else
		return this->_array[i];
}

template <typename T>
T Array< T >::operator[](unsigned int i) const {
	if (this->_size == 0 || i < 0 || i > this->_size - 1)
		throw std::exception();
	else
		return this->_array[i];
}

template<typename T>
std::ostream & operator<<(std::ostream & o, Array< T > & src)
{
	int i = 0;
	std::cout << "Size of array: " << src.size() << std::endl;
	while (i < src.size())
	{
		o << "index " << i << ": " << src[i] << std::endl;
		i++;
	}
	return o;
}

template<typename T>
std::ostream & operator<<(std::ostream & o, const Array< T > & src)
{
	int i = 0;
	std::cout << "Size of array: " << src.size() << std::endl;
	while (i < src.size())
	{
		o << "index " << i << ": " << src[i] << std::endl;
		i++;
	}
	return o;
}

#endif

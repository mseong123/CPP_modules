#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include "data.hpp"

class Serializer {
	public:
		Serializer(void);
		~Serializer(void);
		Serializer(Serializer & src);
		Serializer & operator=(Serializer & src);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
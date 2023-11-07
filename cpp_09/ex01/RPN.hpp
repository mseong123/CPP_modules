#ifndef RPN_HPP
#define RPN_HPP
#include <map>
#include <iostream>
#include <algorithm>
#include <exception>
#include <stack>

class RPN {
	private:
		std::stack<double> _stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN & src);
		RPN & operator=(const RPN & src);
		const std::stack<double> & get_stack() const;
		void parse_input(std::string input);
};

#endif
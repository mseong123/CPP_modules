#include "RPN.hpp"

RPN::RPN() {
	
}

RPN::~RPN() {
}

RPN::RPN(const RPN & src) {
	*this = src;
}

RPN & RPN::operator=(const RPN & src) {
	if (this != &src)
	{
		this->_stack = src.get_stack();
	}
	return *this;
}

const std::stack<double> & RPN::get_stack() const {
	return this->_stack;
}

void RPN::parse_input(std::string input) {
	if (input.find_first_not_of("0123456789+-/* ") != std::string::npos || input.length() == 0)
		std::cout << "Error" << std::endl;
	else {
		std::size_t str_pos = 0;
		double input1 = 0;
		double input2 = 0;
		int	error = 0;
		
		while (str_pos != input.length())
		{
			if (input.substr(str_pos, 1).find_first_of(" ") != std::string::npos) {
				str_pos++;
			}
			else if (input.substr(str_pos, 1).find_first_of("0123456789") != std::string::npos) {
				this->_stack.push(std::stoi(input.substr(str_pos, 1)));
				str_pos += 1;
			}
			else if (input.substr(str_pos, 1) == "-" && input.substr(str_pos + 1, 1).find_first_of("0123456789") != std::string::npos) {
				this->_stack.push(std::stoi(input.substr(str_pos, 2)));
				str_pos += 2;
			}
			else if (input.substr(str_pos, 1) == "+" && this->_stack.size() > 1) {
				input2 = this->_stack.top();
				this->_stack.pop();
				input1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(input1 + input2);
				str_pos += 1;
			}
			else if (input.substr(str_pos, 1) == "-" && this->_stack.size() > 1) {
				input2 = this->_stack.top();
				this->_stack.pop();
				input1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(input1 - input2);
				str_pos += 1;
			}
			else if (input.substr(str_pos, 1) == "*" && this->_stack.size() > 1) {
				input2 = this->_stack.top();
				this->_stack.pop();
				input1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(input1 * input2);
				str_pos += 1;
			}
			else if (input.substr(str_pos, 1) == "/" && this->_stack.size() > 1) {
				input2 = this->_stack.top();
				this->_stack.pop();
				input1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(input1 / input2);
				str_pos += 1;
			}
			else
			{
				error = 1;
				break;
			}
		}
		if (this->_stack.size() > 1 || this->_stack.empty() || error == 1)
			std::cout<<"Error"<<std::endl;
		else
			std::cout<< this->_stack.top() <<std::endl;
	}
}


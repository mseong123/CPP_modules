#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::~ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(ScalarConverter & src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter & src) {
	return *this;
}

bool ScalarConverter::checkChar(void) {
	if (ScalarConverter::_string.length() == 1 && ScalarConverter::_string[0] > 31 && ScalarConverter::_string[0] < 127 
	&& std::isalpha(ScalarConverter::_string[0]))
	{
		ScalarConverter::_c = ScalarConverter::_string[0];
		return true;
	}
	return false;
}

bool ScalarConverter::checkFloat(void) {
	try {
		ScalarConverter::_f = std::stof(ScalarConverter::_string);
		return true;
	}
	catch (std::exception & e)
	{
		return false;
	}
}

bool ScalarConverter::checkDouble(void) {
	try {
		ScalarConverter::_d = std::stod(ScalarConverter::_string);
		return true;
	}
	catch (std::exception & e)
	{
		return false;
	}
}

bool ScalarConverter::checkInteger(void) {
	try {
		ScalarConverter::_i = std::stod(ScalarConverter::_string);
		return true;
	}
	catch (std::exception & e)
	{
		return false;
	}
}

void	ScalarConverter::checkType() {
	if (ScalarConverter::checkChar())
		ScalarConverter::_type = CHAR;
	else if (ScalarConverter::checkFloat())
		ScalarConverter::_type = FLOAT;
	else if (ScalarConverter::checkDouble())
		ScalarConverter::_type = DOUBLE;
	else if (ScalarConverter::checkInteger())
		ScalarConverter::_type = INTEGER;
	else
		ScalarConverter::_type = UNKNOWN;
}

void ScalarConverter::doAllConversion(void) {
	switch(ScalarConverter::_type) {
	case CHAR:
		ScalarConverter::_f = static_cast<float>(ScalarConverter::_c);
		ScalarConverter::_d = static_cast<double>(ScalarConverter::_c);
		ScalarConverter::_i = static_cast<int>(ScalarConverter::_c);
		break;
	case FLOAT:
		ScalarConverter::_c = static_cast<char>(ScalarConverter::_f);
		ScalarConverter::_d = static_cast<double>(ScalarConverter::_f);
		ScalarConverter::_i = static_cast<int>(ScalarConverter::_f);
		break;
	case DOUBLE:
		ScalarConverter::_c = static_cast<char>(ScalarConverter::_d);
		ScalarConverter::_f = static_cast<float>(ScalarConverter::_d);
		ScalarConverter::_i = static_cast<int>(ScalarConverter::_d);
		break;
	case INTEGER:
		ScalarConverter::_c = static_cast<char>(ScalarConverter::_i);
		ScalarConverter::_f = static_cast<float>(ScalarConverter::_i);
		ScalarConverter::_d = static_cast<double>(ScalarConverter::_i);
		break;
	default:
		break;
	}
}

void ScalarConverter::printConversion(void) {
	if (ScalarConverter::_type == UNKNOWN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		ScalarConverter::printChar();
		ScalarConverter::printInt();
		ScalarConverter::printFloat();
		ScalarConverter::printDouble();
	}
}

void ScalarConverter::printChar(void) {
	if (ScalarConverter::_string == "-inff" || ScalarConverter::_string == "+inff"
	|| ScalarConverter::_string == "nanf" || ScalarConverter::_string == "-inf" 
	|| ScalarConverter::_string == "+inf" || ScalarConverter::_string == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (ScalarConverter::_c < 32 || ScalarConverter::_c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << ScalarConverter::_c << "'"<< std::endl;
}

void ScalarConverter::printInt(void) {
	if (ScalarConverter::_string == "-inff" || ScalarConverter::_string == "+inff"
	|| ScalarConverter::_string == "nanf" || ScalarConverter::_string == "-inf" 
	|| ScalarConverter::_string == "+inf" || ScalarConverter::_string == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << ScalarConverter::_i << std::endl;
}

void ScalarConverter::printFloat(void) {
	if (ScalarConverter::_string == "+inff" || ScalarConverter::_string == "+inf"
	|| ScalarConverter::_string == "-inff" || ScalarConverter::_string == "-inf"
	|| ScalarConverter::_string == "nanf" || ScalarConverter::_string == "nan")
		std::cout << "float: " << ScalarConverter::_f << "f" << std::endl;
	else if (ScalarConverter::_f - static_cast<int>(ScalarConverter::_f) == 0)
		std::cout << "float: " << ScalarConverter::_f << ".0f" << std::endl;
	else
		std::cout << "float: " << ScalarConverter::_f << "f" << std::endl;
}

void ScalarConverter::printDouble(void) {
	if (ScalarConverter::_d - static_cast<int>(ScalarConverter::_d) == 0)
		std::cout << "double: " << ScalarConverter::_d << ".0" << std::endl;
	else
		std::cout << "double: " << ScalarConverter::_d << std::endl;
}

void ScalarConverter::convert(std::string input) {
	ScalarConverter::_string = input;
	ScalarConverter::checkType();
	ScalarConverter::doAllConversion();
	ScalarConverter::printConversion();
}

std::string ScalarConverter::getString() const {
	return this->_string;
}

std::string ScalarConverter::_string = "";
char ScalarConverter::_c = 0;
float ScalarConverter::_f = 0.0f;
double ScalarConverter::_d = 0.0;
int ScalarConverter::_i = 0;
int ScalarConverter::_type = UNKNOWN;

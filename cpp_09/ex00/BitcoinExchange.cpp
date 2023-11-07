#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src) {
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & src) {
	if (this != &src)
	{
		this->_map = src.get_map();
	}
	return *this;
}

const std::map<time_t, double> & BitcoinExchange::get_map() const {
	return this->_map;
}

void BitcoinExchange::read_data(std::string filename) {
	std::fstream fs(filename, std::fstream::in);
	if (!fs.is_open())
		throw std::exception();
	else {
		std::string first_line;
		std::getline(fs, first_line);
		std::string line;
		std::string key;
		double value;
		std::size_t comma_pos;
		struct tm tm;
		time_t time;
		while(std::getline(fs, line, '\n')) {
			comma_pos = line.find(',');
			key = line.substr(0, comma_pos);
			value = std::stod(line.substr(comma_pos + 1));
			strptime(key.c_str(), "%Y-%m-%d", &tm);
			time = mktime(&tm);
			this->_map.insert(std::pair<time_t, double> (time, value));
		}
	}
}

void BitcoinExchange::parse_input(std::fstream & input) {
	std::string line;
	std::getline(input, line, '\n');
	std::size_t delimiter_pos;
	std::string date_string;
	std::string delimiter_string;
	std::size_t value_pos;
	std::string value;
	struct tm tm = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	if (line != "date | value")
		throw std::exception();
	while (std::getline(input, line))
	{
		delimiter_pos = line.find_first_not_of("0123456789-");
		if (delimiter_pos == std::string::npos)
			delimiter_pos = line.length();
		date_string = line.substr(0, delimiter_pos);
		delimiter_string = line.substr(delimiter_pos, line.find_first_of("0123456789-", delimiter_pos) - delimiter_pos);
		value_pos = line.find_first_of("-0123456789", delimiter_pos);
		if (value_pos == std::string::npos)
			value_pos = line.length();
		value = line.substr(value_pos);
		
		if (!BitcoinExchange::check_date_format(date_string, &tm) || date_string.length() > 10)
			std::cout << "Error: bad input => " << date_string << std::endl;
		else if (!BitcoinExchange::check_delimiter_format(delimiter_string))
			std::cout << "Error: bad delimiter => " << delimiter_string << std::endl;
		else if (!BitcoinExchange::check_value(value))
			std::cout << "Error: not a float or integer." << std::endl;
		else if (!BitcoinExchange::check_positive_value(value))
			std::cout << "Error: not a positive number." << std::endl;
		else if (!BitcoinExchange::check_large_value(value))
			std::cout << "Error: too large a number." << std::endl;
		else {
			BitcoinExchange::find_convert(date_string, value);
		}
		
	}
}

bool BitcoinExchange::check_date_format(std::string date_string, struct tm *tm) {
	if (!strptime(date_string.c_str(), "%Y-%m-%d", tm))
        return false;
	else if (tm->tm_mon == 1 && tm->tm_mday > 28)
		return false;
	else if (tm->tm_mon < 7 && tm->tm_mon % 2 == 1 && tm->tm_mday == 31)
		return false;
	else if (tm->tm_mon < 12 && tm->tm_mon >= 7 && tm->tm_mon % 2 == 0 && tm->tm_mday == 31)
		return false;
	else if (tm->tm_mday == 0)
		return false;
	else
		return true;
}


bool BitcoinExchange::check_delimiter_format(std::string delimiter_string) {
	if (delimiter_string != " | ")
		return false;
	else
		return true;
}

bool BitcoinExchange::check_value(std::string value) {
	if (value.find_first_not_of("-0123456789.") != std::string::npos 
	|| (value.find("-") != std::string::npos && value.find("-") != 0) || value.find_first_of("-", value.find_first_of("-")+1) != std::string::npos)
		return (false);
	try {
		std::stod(value);
	}
	catch (std::exception & e) {
		return (false);
	}
	return (true);
}

bool BitcoinExchange::check_positive_value(std::string value) {
	if (std::stod(value) < 0)
		return false;
	else
		return true;
}

bool BitcoinExchange::check_large_value(std::string value) {
	if (std::stod(value) > 1000)
		return false;
	else
		return true;
}

void BitcoinExchange::find_convert(std::string date_string, std::string value) {
	struct tm tm;
	time_t time;

	strptime(date_string.c_str(), "%Y-%m-%d", &tm);
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	time = mktime(&tm);
	std::map<time_t, double>::iterator it = this->_map.find(time);
	std::map<time_t, double>::iterator it_lower_bound = this->_map.lower_bound(time);
	
	if (it == this->_map.end() && (it_lower_bound == this->_map.begin() || it_lower_bound == this->_map.end()))
		std::cout << "Error: date not found in database" << std::endl;
	else if (it != this->_map.end()) {
		std::cout << date_string << " => " << value << " = " << std::setprecision(10) << it->second * std::stod(value) << std::endl;
	}
	else {
		it_lower_bound--;
		std::cout << date_string << " => " << value << " = " << std::setprecision(10) << it_lower_bound->second * std::stod(value) << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, BitcoinExchange & src) {
	std::map<time_t, double> map = src.get_map();
	std::map<time_t, double>::iterator it = map.begin();
	std::map<time_t, double>::iterator ite = map.end();
	for (; it != ite; it++) {
		o << "key=" << it->first << ",value=" << std::setprecision(10) << it->second << std::endl;
	}
	return o;
}

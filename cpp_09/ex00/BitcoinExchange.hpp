#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <ctime>
#include <cctype>

class BitcoinExchange {
	private:
		std::map<time_t, double> _map;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator=(const BitcoinExchange & src);
		const std::map<time_t, double> & get_map() const;
		void read_data(std::string filename);
		void parse_input(std::fstream & input);
		bool check_date_format(std::string line, struct tm *tm);
		bool check_delimiter_format(std::string delimiter_string);
		bool check_value(std::string value);
		bool check_positive_value(std::string value);
		bool check_large_value(std::string value);
		void find_convert(std::string date_string, std::string value);
};

std::ostream & operator<<(std::ostream & o, BitcoinExchange & src);


#endif
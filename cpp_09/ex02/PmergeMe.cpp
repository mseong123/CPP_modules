#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe & src) {
	*this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe & src) {
	if (this != &src)
	{
		this->_vec = src.get_vec();
		this->_list = src.get_list();
	}
	return *this;
}

std::vector<int> & PmergeMe::get_vec() {
	return this->_vec;
}

std::list<int> & PmergeMe::get_list() {
	return this->_list;
}

long long PmergeMe::get_time_vec() {
	return this->_end_timestamp_vec.count() - this->_start_timestamp_vec.count();
}
long long PmergeMe::get_time_list() {
	return this->_end_timestamp_list.count() - this->_start_timestamp_list.count();
}

void PmergeMe::parse_input(int argc, char **argv) {
	int i = 1;
	std::string input;

	while (i < argc) {
		std::string arg(argv[i]);
		if (arg.find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::InputErrorException();
		else if (i == 1)
			input += "Before: " + arg;
		else
			input += " " + arg;
		i++;
	}
	std::cout << input << std::endl;
}

bool PmergeMe::customCompare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

void PmergeMe::insert_vec(std::vector<std::pair<int,int> > & temp, int odd) {
	for (std::vector<std::pair<int, int> >::iterator it = temp.begin(); it != temp.end(); it++) {
		if (this->_vec.empty()) {
			this->_vec.push_back((*it).first);
			this->_vec.push_back((*it).second);
		}
		else {
			this->_vec.insert(std::lower_bound(this->_vec.begin(), this->_vec.end(), (*it).first), (*it).first);
			this->_vec.push_back((*it).second);
		}
	}
	if (odd != -1)
		this->_vec.insert(std::lower_bound(this->_vec.begin(), this->_vec.end(), odd), odd);
	this->_end_timestamp_vec = std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::system_clock::now().time_since_epoch());
}

void PmergeMe::sort_vec(int argc, char **argv) {
	std::vector<std::pair<int,int> > temp;
	int first_pair = -1;
	int second_pair = -1;
	int i = 1;
	this->_start_timestamp_vec = std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::system_clock::now().time_since_epoch());

	while (i < argc) {
		std::string arg(argv[i++]);
		if (first_pair == -1) {
			first_pair = std::stoi(arg);
			second_pair = -1;
		}
		else {
			second_pair = std::stoi(arg);
			if (first_pair < second_pair)
				temp.push_back(std::make_pair(first_pair, second_pair));
			else
				temp.push_back(std::make_pair(second_pair, first_pair));
			first_pair = -1;
		}
	}
	std::sort(temp.begin(), temp.end(), PmergeMe::customCompare);
	if (first_pair != -1 && second_pair == -1)
		PmergeMe::insert_vec(temp, first_pair);
	else
		PmergeMe::insert_vec(temp, -1);
}

void PmergeMe::insert_list(std::list<std::pair<int,int> > & temp, int odd) {
	for (std::list<std::pair<int, int> >::iterator it = temp.begin(); it != temp.end(); it++) {
		if (this->_list.empty()) {
			this->_list.push_back((*it).first);
			this->_list.push_back((*it).second);
		}
		else {
			this->_list.insert(std::lower_bound(this->_list.begin(), this->_list.end(), (*it).first), (*it).first);
			this->_list.push_back((*it).second);
		}
	}
	if (odd != -1)
		this->_list.insert(std::lower_bound(this->_list.begin(), this->_list.end(), odd), odd);
	this->_end_timestamp_list = std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::system_clock::now().time_since_epoch());
}

void PmergeMe::sort_list(int argc, char **argv) {
	std::list<std::pair<int,int> > temp;
	int first_pair = -1;
	int second_pair = -1;
	int i = 1;
	this->_start_timestamp_list = std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::system_clock::now().time_since_epoch());

	while (i < argc) {
		std::string arg(argv[i++]);
		if (first_pair == -1) {
			first_pair = std::stoi(arg);
			second_pair = -1;
		}
		else {
			second_pair = std::stoi(arg);
			if (first_pair < second_pair)
				temp.push_back(std::make_pair(first_pair, second_pair));
			else
				temp.push_back(std::make_pair(second_pair, first_pair));
			first_pair = -1;
		}
	}
	std::vector<std::pair<int, int> > tempVector(temp.begin(), temp.end());
    std::sort(tempVector.begin(), tempVector.end(), customCompare);
    temp.assign(tempVector.begin(), tempVector.end());
	if (first_pair != -1 && second_pair == -1)
		PmergeMe::insert_list(temp, first_pair);
	else
		PmergeMe::insert_list(temp, -1);
}

void PmergeMe::compare_results(std::list<int> & list)  {
	std::vector<int> vec_temp(list.begin(), list.end());
	if (vec_temp != this->_vec)
		throw PmergeMe::ResultErrorException();
}

const char *PmergeMe::InputErrorException::what() const throw() {
	return "Error: Incorrect input";
}

const char *PmergeMe::ResultErrorException::what() const throw() {
	return "Error: Result of containers sort different";
}

std::ostream & operator<<(std::ostream & o, PmergeMe & src) {
	std::vector<int> vec = src.get_vec();
	std::vector<int>::iterator it;
	std::vector<int>::iterator ite;
	for (; it != ite; it++) {
		o << "value = " << *it << std::endl;
	}
	return o;
}

std::ostream & operator<<(std::ostream & o, std::vector<std::pair<int, int> > & src) {
	std::vector<std::pair<int, int> >::iterator it = src.begin();
	std::vector<std::pair<int, int> >::iterator ite = src.end();
	for (; it != ite; it++) {
		o << "first=" << (*it).first << "second=" << (*it).second<<std::endl;
	}
	return o;
}

std::ostream & operator<<(std::ostream & o, std::vector<int> & src) {
	std::vector<int>::iterator it = src.begin();
	std::vector<int>::iterator ite = src.end();
	for (; it != ite; it++) {
		o << " " << *it;
	}
	return o;
}

std::ostream & operator<<(std::ostream & o, std::list<int> & src) {
	std::list<int>::iterator it = src.begin();
	std::list<int>::iterator ite = src.end();
	for (; it != ite; it++) {
		o << " " << *it <<std::endl;
	}
	return o;
}






#ifndef PmergeMe_HPP
#define PmergeMe_HPP
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <chrono>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::list<int> _list;
		std::chrono::microseconds _start_timestamp_vec;
		std::chrono::microseconds _end_timestamp_vec;
		std::chrono::microseconds _start_timestamp_list;
		std::chrono::microseconds _end_timestamp_list;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe & src);
		PmergeMe & operator=(PmergeMe & src);
		std::vector<int> & get_vec();
		std::list<int> & get_list();
		long long get_time_vec();
		long long get_time_list();
		void parse_input(int argc, char **argv);
		void insert_vec(std::vector<std::pair<int,int> > & temp, int odd);
		void sort_vec(int argc, char **argv);
		void insert_list(std::list<std::pair<int,int> > & temp, int odd);
		void sort_list(int argc, char **argv);
		static bool customCompare(const std::pair<int, int> & a, const std::pair<int, int> & b);
		void compare_results(std::list<int> & list);
		class InputErrorException : public std::exception {
			public:
				const char *what() const throw();
		};
		class ResultErrorException : public std::exception {
			public:
				const char *what() const throw();
		};
};



std::ostream & operator<<(std::ostream & o, PmergeMe & src);
std::ostream & operator<<(std::ostream & o, std::vector<std::pair<int, int> > & src);
std::ostream & operator<<(std::ostream & o, std::vector<int> & src) ;
std::ostream & operator<<(std::ostream & o, std::list<int> & src) ;

#endif
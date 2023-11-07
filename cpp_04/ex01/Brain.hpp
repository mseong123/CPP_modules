#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain & src);
		Brain & operator=(Brain & src);
		std::string *get_ideas(void);
};

#endif
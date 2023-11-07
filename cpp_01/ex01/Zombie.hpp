#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	
	private:
		std::string _name;
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
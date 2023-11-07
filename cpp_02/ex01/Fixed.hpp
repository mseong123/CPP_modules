#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
	private:
		int	_value;
		static const int _fract;
	public:
		Fixed(void);
		Fixed(Fixed const & fixed);
		Fixed(int const value);
		Fixed(float const value);
		Fixed & operator=(Fixed const & fixed);
		~Fixed(void);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif
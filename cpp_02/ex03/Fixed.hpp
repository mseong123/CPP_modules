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
		bool operator>(Fixed const & fixed) const;
		bool operator<(Fixed const & fixed) const;
		bool operator>=(Fixed const & fixed) const;
		bool operator<=(Fixed const & fixed) const;
		bool operator==(Fixed const & fixed) const;
		bool operator!=(Fixed const & fixed) const;
		Fixed operator+(Fixed const & fixed) const;
		Fixed operator-(Fixed const & fixed) const;
		Fixed operator*(Fixed const & fixed) const;
		Fixed operator/(Fixed const & fixed) const;
		Fixed & operator++(void);
		Fixed operator++(int);
		Fixed & operator--(void);
		Fixed operator--(int);
		static Fixed & min(Fixed & first, Fixed & second);
		static Fixed & max(Fixed & first, Fixed & second);
		static const Fixed & min(Fixed const & first, Fixed const & second);
		static const Fixed & max(Fixed const & first, Fixed const & second);


};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif
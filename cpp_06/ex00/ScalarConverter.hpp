#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# define UNKNOWN 0
# define CHAR 1
# define FLOAT 2
# define DOUBLE 3
# define INTEGER 4
# include <iostream>
# include <stdexcept>

class ScalarConverter {
	private:
		static	std::string	_string;
		static	char	_c;
		static	float	_f;
		static	double	_d;
		static	int		_i;
		static	int		_type;
		static	bool	checkChar(void);
		static	bool	checkFloat(void);
		static	bool	checkDouble(void);
		static	bool	checkInteger(void);
		static	void	checkType(void);
		static	void	doAllConversion(void);
		static	void	printConversion(void);
		static	void	printChar(void);
		static	void	printFloat(void);
		static	void	printInt(void);
		static	void	printDouble(void);
		static	void	convertChar(void);
		static	void	convertFloat(void);
		static	void	convertDouble(void);
		static	void	convertInt(void);
	public:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(ScalarConverter & src);
		ScalarConverter & operator=(ScalarConverter &src);
		static	void	convert(std::string input);
		std::string getString(void) const;
		
};

#endif
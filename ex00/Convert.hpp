#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <string>

class Convert {

private:
	Convert(Convert const & src);
	Convert & operator=(Convert const & rhs);
	Convert();
	std::string const	_value;
	int					_cvalue;
	int					_ivalue;
	float				_fvalue;
	double				_dvalue;
	bool				_isLitteral;

public:
	Convert(std::string const & str);
	~Convert();
	operator	char() const;
	operator	int() const;
	operator	float() const;
	operator	double() const;
	int			isnan(double x) const;
	int			isinf(double x) const;
	int			getValueLength( void ) const;
	void		convLiterral( void );
	void		checkArg( void ) const;
	class ImpossibleConvException : public std::exception
	{
		public :
			virtual char const * what( void ) const throw();
	};
	class BadParamException : public std::exception
	{
		public :
			virtual char const * what( void ) const throw();
	};

};


#endif

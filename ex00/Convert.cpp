#include "Convert.hpp"
#include "errno.h"
#include <typeinfo>


Convert::Convert(std::string const & str) :
_value(str), _ivalue(0), _fvalue(0), _dvalue(0), _isLitteral(false)  {

	try
	{
		convLiterral();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void		Convert::checkArg( void ) const
{
	int i = 0;
	if (!_isLitteral)
	{
		while(isspace(_value[i]))
			i++;
		if ((_value[i] == '-' || _value[i] == '+'))
		{
			if (!isdigit(_value[i + 1]))
				throw BadParamException();
		}
		else if (!isdigit(_value[i]))
			throw BadParamException();
	}
}

void		Convert::convLiterral( void )
{
	std::string literrals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan", "inf", "inff"};

	for (int i = 0; i < static_cast<int>(sizeof(literrals)/sizeof(literrals[0])) ; i++)
		if (_value == literrals[i])
			_isLitteral = true;
	if (_isLitteral)
	{
		_dvalue = std::atof(_value.c_str());
		if (errno)
			throw ImpossibleConvExceptin();
		_fvalue = (float) _dvalue;
		_ivalue = std::atoi(_value.c_str());
 	}
	else
	{
		_dvalue = std::atof(_value.c_str());
		if (errno)
			throw ImpossibleConvExceptin();
		_fvalue = (float) _dvalue;
		_ivalue = std::atoi(_value.c_str());
	}
}

Convert::~Convert() {}

Convert::operator char() const
{
	if (_isLitteral)
		throw ImpossibleConvExceptin();
	else
		return _ivalue;
}

Convert::operator double() const
{
	return _dvalue;
}

Convert::operator float() const
{
	return _fvalue;
}

Convert::operator int() const
{
	if (_isLitteral)
		throw ImpossibleConvExceptin();
	else
		return _ivalue;
}

char const * Convert::ImpossibleConvExceptin::what( void ) const throw()
{
	return "impossible";
}

char const * Convert::BadParamException::what( void ) const throw()
{
	return "Bad parameter, not a number";
}

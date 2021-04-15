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
		if (_value.length() != 1)
		{
			while(isspace(_value[i]))
				i++;
			if ((_value[i] == '-' || _value[i] == '+'))
			{
				if (!isdigit(_value[i + 1]))
					throw ImpossibleConvException();
			}
			else if (!isdigit(_value[i]))
				throw ImpossibleConvException();
		}
	}
}

void		Convert::convLiterral( void )
{
	std::string literrals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan", "inf", "inff"};

	if (_value.length() == 1 && !isdigit(_value[0]))
	{
		_dvalue = static_cast<double>(_value[0]);
		_fvalue = static_cast<float>(_dvalue);
		_ivalue = static_cast<int>(_dvalue);
		return ;
	}
	for (int i = 0; i < static_cast<int>(sizeof(literrals)/sizeof(literrals[0])) ; i++)
		if (_value == literrals[i])
			_isLitteral = true;
	if (_isLitteral)
	{
		_dvalue = strtod(_value.c_str(), NULL);
		if (errno)
			throw ImpossibleConvException();
		_fvalue = static_cast<float>(_dvalue);
		_ivalue = static_cast<int>(_dvalue);
 	}
	else
	{
		_dvalue = strtod(_value.c_str(), NULL);
		if (errno)
			throw ImpossibleConvException();
		_fvalue = (float) _dvalue;
		_ivalue = std::atoi(_value.c_str());
	}
}

Convert::~Convert() {}

Convert::operator char() const
{
	if (_isLitteral)
		throw ImpossibleConvException();
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
		throw ImpossibleConvException();
	else
		return _ivalue;
}

int Convert::getValueLength( void ) const
{
	return _value.length();
}

char const * Convert::ImpossibleConvException::what( void ) const throw()
{
	return "impossible";
}

char const * Convert::BadParamException::what( void ) const throw()
{
	return "Bad parameter, not a number";
}

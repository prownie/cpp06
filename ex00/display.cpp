#include "Convert.hpp"
#include <iomanip>
#include <cmath>
#include <limits>

void	display(Convert & conv)
{
	try
	{
		std::cout << "char: ";
		conv.checkArg();
		char c = static_cast<char>(conv);
		if (isprint(c) && (static_cast<int>(conv) >= 0 && static_cast<int>(conv) <= 127))
			std::cout << "'" << c << "'" << std::endl;
		else if (!isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			throw Convert::ImpossibleConvException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "int: ";
		conv.checkArg();
		if (static_cast<double>(conv) < std::numeric_limits<int>::lowest() || static_cast<double>(conv) > std::numeric_limits<int>::max())
			throw Convert::ImpossibleConvException();
		int i = static_cast<int>(conv);
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		double integral, fractpart;
		std::cout << "float: ";
		conv.checkArg();
		if (static_cast<double>(conv) < std::numeric_limits<float>::lowest() || static_cast<double>(conv) > std::numeric_limits<float>::max())
			throw Convert::ImpossibleConvException();
		float f = static_cast<float>(conv);
		fractpart = std::modf(f, &integral);
		int i = 0;
		if (fractpart == 0.0)
   			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
		{
			while (fractpart < 1 && ++i)
				fractpart *=10;
    		std::cout << f << "f" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		double integral, fractpart;
		std::cout << "double: ";
		conv.checkArg();
		double d = static_cast<double>(conv);
		fractpart = std::modf(d, &integral);
		int i = 0;
		if (fractpart == 0.0)
   			std::cout << std::fixed << std::setprecision(1) << d << std::endl;
		else
		{
			while (fractpart < 1 && ++i)
				fractpart *=10;
    		std::cout << std::fixed << std::setprecision(i) << d << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

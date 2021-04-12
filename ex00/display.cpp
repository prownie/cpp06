#include "Convert.hpp"
#include <iomanip>
#include <cmath>

void	display(Convert & conv)
{
	try
	{
		std::cout << "char: ";
		char c = static_cast<char>(conv);
		if (isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "int: ";
		int i = static_cast<int>(conv);
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		double integral;
		std::cout << "float: ";
		float f = static_cast<float>(conv);
		if (std::modf(f, &integral) == 0)
   			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
    		std::cout << f << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		double integral;
		std::cout << "double: ";
		double d = static_cast<float>(conv);
		if (std::modf(d, &integral) == 0)
   			std::cout << std::fixed << std::setprecision(1) << d << std::endl;
		else
    		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

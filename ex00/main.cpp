#include "Convert.hpp"

void	display(Convert & conv);

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "Wrong number of parameters. Use ./convert PARAM" << std::endl;
		return 0;
	}

	try
	{
		Convert test(av[1]);
		test.checkArg();
		display(test);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



}

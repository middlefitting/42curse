#include "Harl.hpp"

int	main(int argc, char* argv[]) {
	if (argc != 2)
	{
		std::cout << "ERROR: Argument must be 1" << std::endl;
		return 1;
	}
	Harl harl;
	harl.harlFilter(argv[1]);
	return 0;
}

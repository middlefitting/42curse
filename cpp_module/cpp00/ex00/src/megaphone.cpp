#include <iostream>
#include <cstring>

void	print_logic(char str[])
{
	for (int i = 0; i < (int) strlen(str); i++)
		std::cout << (char) toupper(str[i]);
}

void	printer(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
		print_logic(argv[i]);
	std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		printer(argc, argv);
	return (0);
}

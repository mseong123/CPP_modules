#include <iostream>

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	if (argc > 1)
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i] && argv[i][j])
				std::cout << (char)std::toupper(argv[i][j++]);
			i++;
		}
		std::cout << "\n";
	}
	else if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}

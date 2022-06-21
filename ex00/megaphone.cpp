#include <string>
#include <iostream>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			for (size_t j = 0; j < (size_t)strlen(av[i]); j++)
				std::cout << (char)toupper(av[i][j]);
		}
			std::cout << "\n";
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}

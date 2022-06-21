//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "ex01.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string	get_input(const std::string& prompt)
{
	std::string	input;

	std::cout << prompt;
  	std::getline(std::cin, input);
	while (input.empty() || !(std::isalnum(input[0])))
	{
		std::cout << prompt;
  		std::getline(std::cin, input);
	}
	return (input);
}

int	main(void)
{
	PhoneBook	telemovel;
	std::string	input;

	while (1)
	{
		input = get_input("Enter a command: ");
		if (!(input.compare("ADD")))
			telemovel.set_Contact();
		else if (!(input.compare("SEARCH")))
			telemovel.get_Contacts();
		else if (!(input.compare("EXIT")))
			exit(0);
		else
			continue;
	}
}

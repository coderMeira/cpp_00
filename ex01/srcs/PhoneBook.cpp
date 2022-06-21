//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "ex01.hpp"

PhoneBook::PhoneBook() {
	turn = 0;
	lstsize = 0;
}

PhoneBook::PhoneBook(const PhoneBook& param) {
	// TODO (copy constructor)
	(void)param;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook" << " destroyed" << std::endl;
	// TODO (destructor)
}

PhoneBook& PhoneBook::operator= (const PhoneBook& param) {
	// TODO (Assignment operator)
	// std::swap()
	(void)param;
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const PhoneBook& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

int	PhoneBook::get_oldest_contact(void){
	for(int i = 0; i < 8; i++)
	{
		if (_contacts[i].get_assignements() <= turn)
			return (i);
	}
	return (0);
}

int	PhoneBook::get_curr_contact_slot(void){
	if (turn == 0)
	{
		for(int i = 0; i < 8; i++)
		{
			if (_contacts[i].not_assigned())
				return (i);
		}
	}
	return (get_oldest_contact());
}

void	PhoneBook::print_contactlist(void){
	for(int i = 0; i < lstsize; i++)
		_contacts[i].print_contact_trunc(i);
}

void	PhoneBook::set_Contact(void){
	int	i = get_curr_contact_slot();

	if (i < 8 && !turn)
		lstsize++;
	if (i == 7)
		turn++;
	_contacts[i].assign();
	_contacts[i].set_firstName();
	_contacts[i].set_lastName();
	_contacts[i].set_nickname();
	_contacts[i].set_phoneNumber();
	_contacts[i].set_darkestSecret();
}

void	PhoneBook::print_header(void){
	std::cout << "|";
	std::cout << "     index|";
	std::cout << "first name|";
	std::cout << " last name|";
	std::cout << "  nickname|";
	std::cout << std::endl;
}

void	PhoneBook::prompt_index(void){
	std::string	input;
	int			i;

	std::cout << "Enter contact index to search: ";
  	std::getline(std::cin, input);
	while (input.empty() || !(std::isdigit(input[0])) || input[1])
	{
		std::cout << "Enter (a valid) contact index to search: ";
  		std::getline(std::cin,input);
	}
	i = std::atoi(input.c_str());
	while (i < 0 || i > 7)
	{
		std::cout << "Enter (a valid) contact index to search: ";
  		std::getline(std::cin,input);
	}
	if (_contacts[i].not_assigned())
		std::cout << "There is no contact for this index\n";
	else
		_contacts[i].print_contact_full();
}

void	PhoneBook::get_Contacts(void){
	print_header();
	print_contactlist();
	prompt_index();
}


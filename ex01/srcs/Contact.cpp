//***************************//
//*Template by pulgamecanica*//
//***************************//

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "ex01.hpp"
#include <typeinfo>

Contact::Contact() {
	assignements = 0;
}

Contact::Contact(const Contact& param) {
	// TODO (copy constructor)
	(void)param;
}

Contact::~Contact() {
	std::cout << "Contact" << " destroyed" << std::endl;
	// TODO (destructor)
}

Contact& Contact::operator= (const Contact& param) {
	// TODO (Assignment operatior)
	// std::swap()
	(void)param;
	return (*this);
}

std::ostream& operator<<(std::ostream& s, const Contact& param) {
	// s << param.CONST_METHOD()
	(void)param;
	return (s);
}

bool	Contact::not_assigned(void){
	if (firstName.empty())
		return (true);
	return (false);
}

int		Contact::get_assignements(void){
	return (assignements);
}

void	Contact::assign(void){
	assignements++;
}

void	Contact::set_firstName(void){
	firstName = get_input("Enter a first name: ");
}

void	Contact::set_lastName(void){
	lastName = get_input("Enter a last name: ");
}

void	Contact::set_nickname(void){
	nickname = get_input("Enter a nickname: ");
}

bool	Contact::not_valid_phoneNumber(void){
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!(std::isdigit(phoneNumber[i])))
			return (true);
	}
	return (false);
}

void	Contact::set_phoneNumber(void){
	phoneNumber = get_input("Enter a your phone number: ");
	while (not_valid_phoneNumber())
	{
		std::cout << "Enter (a valid) phone number: ";
  		std::getline(std::cin,phoneNumber);
	}
}

void	Contact::set_darkestSecret(void){
	darkestSecret = get_input("Enter your darkest secret: ");
}

void	Contact::print_contact_trunc(int i){
	std::cout << "|";
	std::cout << "         " << i;
	std::cout << "|";
	if (!firstName.empty())
	{
		if (firstName.length() > 10)
			std::cout << firstName.substr(0, 9) << ".";
		else
		{
			for (u_long i = (10 - firstName.length()); i != 0; i--)
				std::cout << " ";
			std::cout << firstName;
		}
	}
	std::cout << "|";
	if (!lastName.empty())
	{
		if (lastName.length() > 10)
			std::cout << lastName.substr(0, 9) << ".";
		else
		{
			for (u_long i = (10 - lastName.length()); i != 0; i--)
				std::cout << " ";
			std::cout << lastName;
		}
	}
	std::cout << "|";
	if (!nickname.empty())
	{
		if (nickname.length() > 10)
			std::cout << nickname.substr(0, 9) << ".";
		else
		{
			for (u_long i = (10 - nickname.length()); i != 0; i--)
				std::cout << " ";
			std::cout << nickname;
		}
	}
	std::cout << "|" << std::endl;
}

void	Contact::print_contact_full(void){
	std::cout << "first name = " << firstName << std::endl;
	std::cout << "last name = " << lastName << std::endl;
	std::cout << "nickname = " << nickname << std::endl;
	std::cout << "phone number = " << phoneNumber << std::endl;
	std::cout << "darkest secret = " << darkestSecret << std::endl;
}


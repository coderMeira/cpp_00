//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

#include <iostream>
#include <string>

class Contact {
	public:
		Contact();
		Contact(const Contact&);
		~Contact();
		void	set_firstName(void);
		void	set_lastName(void);
		void	set_nickname(void);
		void	set_phoneNumber(void);
		void	set_darkestSecret(void);
		bool	not_assigned(void);
		int		get_assignements(void);
		void	assign(void);
		void	print_contact_trunc(int i);
		void	print_contact_full(void);
		bool	not_valid_phoneNumber(void);
		Contact&	operator= (const Contact&); // const for safety... not super nesessary

	private:
		int			assignements;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

std::ostream&	operator<<(std::ostream&, const Contact&);

#endif


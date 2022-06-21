//***************************//
//*Template by pulgamecanica*//
//***************************//

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &copy);
		~PhoneBook();
		PhoneBook&	operator= (const PhoneBook &rhs); // const for safety... not super nesessary
		void		set_Contact(void);
		void		get_Contacts(void);
		int			get_curr_contact_slot(void);
		void		print_contactlist(void);
		void		print_header(void);
		int			get_oldest_contact(void);
		void		prompt_index(void);
	private:
		Contact _contacts[8];
		int		turn;
		int		lstsize;
};


std::ostream&	operator<<(std::ostream&, const PhoneBook&);

#endif

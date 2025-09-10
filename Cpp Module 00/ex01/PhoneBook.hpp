#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		void setContactFirstName(int i, std::string first_name);
		void setContactLastName(int i, std::string last_name);
		void setContactNickName(int i, std::string nickname);
		void setContactPhoneNumber(int i, std::string phone_number);
		void setContactDarkestSecret(int i, std::string darkest_secret);
		std::string getContactFirstName(int i);
		std::string getContactLastName(int i);
		std::string getContactNickName(int i);
		std::string getContactPhoneNumber(int i);
		std::string getContactDarkestSecret(int i);
};

#endif
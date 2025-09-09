/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:35:40 by aychikhi          #+#    #+#             */
/*   Updated: 2025/09/09 11:31:06 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
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
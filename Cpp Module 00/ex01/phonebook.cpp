/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:28:18 by aychikhi          #+#    #+#             */
/*   Updated: 2025/09/08 15:24:35 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::setContactFirstName(int i, std::string first_name)
{
	if (i >= 0 && i < 8)
		contact[i].setFirstName(first_name);
}

std::string PhoneBook::getContactFirstName(int i)
{
	if (i >= 0 && i < 8)
		return contact[i].getFirstName();
	static std::string empty = "";
	return empty;
}

void PhoneBook::setContactLastName(int i, std::string last_name)
{
	if (i >= 0 && i < 8)
		contact[i].setLastName(last_name);
}

std::string PhoneBook::getContactLastName(int i)
{
	if (i >= 0 && i < 8)
		return contact[i].getLastName();
	static std::string empty = "";
	return empty;
}

void PhoneBook::setContactNickName(int i, std::string nickname)
{
	if (i >= 0 && i < 8)
		contact[i].setNickName(nickname);
}

std::string PhoneBook::getContactNickName(int i)
{
	if (i >= 0 && i < 8)
		return contact[i].getNickName();
	static std::string empty = "";
	return empty;
}

void PhoneBook::setContactPhoneNumber(int i, std::string phone_number)
{
	if (i >= 0 && i < 8)
		contact[i].setPhoneNumber(phone_number);
}

std::string PhoneBook::getContactPhoneNumber(int i)
{
	if (i >= 0 && i < 8)
		return contact[i].getPhoneNumber();
	static std::string empty = "";
	return empty;
}

void PhoneBook::setContactDarkestSecret(int i, std::string darkestsecret)
{
	if (i >= 0 && i < 8)
		contact[i].setDarkestSecret(darkestsecret);
}

std::string PhoneBook::getContactDarkestSecret(int i)
{
	if (i >= 0 && i < 8)
		return contact[i].getDarkestSecret();
	static std::string empty = "";
	return empty;
}

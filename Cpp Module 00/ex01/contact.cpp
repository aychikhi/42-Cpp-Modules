#include "Contact.hpp"

void Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}

std::string Contact::getFirstName()
{
	return first_name;
}

void Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}

std::string Contact::getLastName()
{
	return last_name;
}

void Contact::setNickName(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::getNickName()
{
	return nickname;
}

void Contact::setPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
}

std::string Contact::getPhoneNumber()
{
	return phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string Contact::getDarkestSecret()
{
	return darkest_secret;
}
#include "PhoneBook.hpp"

void add_firstname(PhoneBook& phonebook, int index)
{
	while (1)
	{	
		std::cout << "first name : ";
		std::string first_name;
		std::getline(std::cin, first_name);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			exit(1);	
		}
		if (first_name.empty()) {
			std::cout << "First name cannot be empty!" << std::endl;
			continue;
		}
		phonebook.setContactFirstName(index, first_name);
		if (!first_name.empty())
			break;
	}
}
void add_lastname(PhoneBook& phonebook, int index)
{
	while (1)
	{	
		std::cout << "last name : ";
		std::string last_name;
		std::getline(std::cin, last_name);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			exit(1);	
		}
		if (last_name.empty()) {
			std::cout << "Last name cannot be empty!" << std::endl;
			continue;
		}
		phonebook.setContactLastName(index, last_name);
		if (!last_name.empty())
			break;
	}
}
void add_nickname(PhoneBook& phonebook, int index)
{
	while (1)
	{	
		std::cout << "nickname : ";
		std::string nickname;
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			exit(1);	
		}
		if (nickname.empty()) {
			std::cout << "Nickname cannot be empty!" << std::endl;
			continue;
		}
		phonebook.setContactNickName(index, nickname);
		if (!nickname.empty())
			break;
	}
}

int check_arg(const char *arg)
{
	int i = 0;
	while(arg[i])
	{
		if (!isdigit(arg[i]))
			return 0;
		i++;
	}
	if (i > 10)
		return 0;
	return 1;
}

void add_phonenumber(PhoneBook& phonebook, int index)
{
	while (1)
	{
		std::cout << "phone number : ";
		std::string phone_number;
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			exit(1);	
		}
		if (phone_number.empty()) {
			std::cout << "Phone number cannot be empty!" << std::endl;
			continue;
		}
		const char *tmp = phone_number.c_str(); 
		if (!check_arg(tmp))
		{
			std::cout << "Invalid Phone number!" << std::endl;
			continue;
		}
		phonebook.setContactPhoneNumber(index, phone_number);
		if (!phone_number.empty())
			break;
	}
}
void add_darkestsecret(PhoneBook& phonebook, int index)
{
	while (1)
	{		
		std::cout << "darkest secret : ";
		std::string darkest_secret;
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			exit(1);	
		}
		if (darkest_secret.empty()) {
			std::cout << "Darkest secret cannot be empty!" << std::endl;
			continue;
		}
		phonebook.setContactDarkestSecret(index, darkest_secret);
		if (!darkest_secret.empty())
			break;
	}
}

void add_contact(PhoneBook& phonebook, int index)
{
	add_firstname(phonebook, index);
	add_lastname(phonebook, index);
	add_nickname(phonebook, index);
	add_phonenumber(phonebook, index);
	add_darkestsecret(phonebook, index);
}

std::string formatField(const std::string& field, size_t width = 10) 
{
    if (field.length() > width)
        return field.substr(0, width - 1) + ".";
	return field;
}

void search_contact(PhoneBook& phonebook, int total_contact)
{
	int i = 0;
	if (total_contact == 0)
	{
		std::cout << "No contacts to display!" << std::endl;
		return;
	}
    std::cout << " ------------------------------------------------" << std::endl;
	std::cout << " | ";
	std::cout << std::setw(5) << "Index" << " | ";
	std::cout << std::setw(10) << "First Name" << " | ";
	std::cout << std::setw(10) << "Last Name" << " | ";
	std::cout << std::setw(10) << "Nickname" << " | " << std::endl ;
    std::cout << " ------------------------------------------------" << std::endl;
	while (i < total_contact)
	{
		std::cout << " | ";
		std::cout << std::setw(5) << i + 1 << " | ";
		std::cout << std::setw(10) << formatField(phonebook.getContactFirstName(i)) << " | ";
		std::cout << std::setw(10) << formatField(phonebook.getContactLastName(i)) << " | ";
		std::cout << std::setw(10) << formatField(phonebook.getContactNickName(i)) << " | " << std::endl;
    	std::cout << " ------------------------------------------------" << std::endl;
		i++;
	}
	while (1)
	{
		std::string index;
		std::cout << "enter the index (between 1 and 8) or 0 for rollback" << std::endl;
		std::getline(std::cin, index);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			exit(1);	
		}
		if (index.empty() || index.size() != 1)
		{
			std::cout << "Invalid index!" << std::endl;
			continue;
		}
		if (index == "0")
			return ;
		else if (index >= "1" && index <= "8")
		{
			int indx = atoi(index.c_str()) - 1;
			if (indx >= total_contact)
			{
				std::cout << "Invalid index!" << std::endl;
				continue;
			}
			std::cout << "First Name : " << phonebook.getContactFirstName(indx) << std::endl;
			std::cout << "Last Name : " << phonebook.getContactLastName(indx) << std::endl;
			std::cout << "Nickname : " << phonebook.getContactNickName(indx) << std::endl;
			std::cout << "Phone Number : " << phonebook.getContactPhoneNumber(indx) << std::endl;
			std::cout << "Darkest Secret : "  << phonebook.getContactDarkestSecret(indx) << std::endl;
			return;
		}
	}
}

int main()
{
	std::string command;
	PhoneBook phonebook;
	int index = 0;
	int total_contact = 0;
	std::cout << "Enter one of this three commands : ADD, SEARCH, EXIT" << std::endl;
	while (1)
	{
		std::cout << "Command : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "\nthala ajmi" << std::endl;
			return 0;
		}
		if (command.empty())
			std::cout << "Command cannot be empty, Enter one of this three commands : ADD, SEARCH, EXIT" << std::endl;
		if (!command.empty())
		{			
			if (command =="ADD")
			{
				std::cout << "Save a new contact!" << std::endl;
				add_contact(phonebook, index);
				index = (index + 1) % 8;
				if (total_contact < 8)
					total_contact++;
			}
			else if (command == "SEARCH")
			{
				search_contact(phonebook, total_contact);
			}
			else if (command == "EXIT")
				break;
			else
				std::cout << "There is only this commands (ADD, SEARCH, EXIT)" << std::endl;
		}
	}
	return (0);
}
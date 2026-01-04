#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	// std::cout << "Intern Default constructor was called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
	// std::cout << "Intern Copy constructor was called" << std::endl;
}

Intern& Intern::operator=(const Intern &obj)
{
	(void)obj;
	// std::cout << "Intern Copy assignment was called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	// std::cout << "Intern Destructor was called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formname[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int index = -1;
	for(int i = 0; i < 3 ; i++)
	{
		if (name == formname[i])
		{
			index = i;
			break;
		}
	}
	switch(index)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern cannot creates '" << name << "' because it doesn't exist." << std::endl;
			return NULL;
	}
}

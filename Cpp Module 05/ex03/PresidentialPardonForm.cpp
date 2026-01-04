#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
    // std::cout << "PresidentialPardonForm1 Constructor was called" << std::endl;
	target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
    // std::cout << "PresidentialPardonForm Parameterized Constructor was called" << std::endl;
	target = obj.target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	// std::cout << "PresidentialPardonForm Copy Constructor was called" << std::endl;
	this->target = target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	// std::cout << "PresidentialPardonForm Copy assignment was called" << std::endl;
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm Destructor was called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getisSigned() == false)
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


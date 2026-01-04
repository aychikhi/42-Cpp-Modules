#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
    // std::cout << "RobotomyRequestForm Constructor was called" << std::endl;
	target = "defaults";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
    // std::cout << "RobotomyRequestForm Parameterized Constructor was called" << std::endl;
	this->target = obj.target;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	// std::cout << "RobotomyRequestForm Copy Constructor was called" << std::endl;
	this->target = target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	// std::cout << "RobotomyRequestForm Copy assignment was called" << std::endl;
	if (this != &obj)
		this->target = obj.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm Destructor was called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getisSigned() == false)
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "* intense drilling noise *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfuly!" << std::endl;
	else
		std::cout << "the robotomy on " << this->target << " failed." << std::endl;
}

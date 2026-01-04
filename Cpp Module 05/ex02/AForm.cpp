#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	// std::cout << "AForm Default constructor was called" << std::endl;
}

AForm::AForm(const AForm &obj) : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	// std::cout << "AForm Copy constructor was called" << std::endl;
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm Parameterized constructor was called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

AForm& AForm::operator=(const AForm &obj)
{
	// std::cout << "AForm Copy assignment was called" << std::endl;
	if (this != &obj)
		isSigned = obj.isSigned;
	return *this;
}

AForm::~AForm()
{
	// std::cout << "AForm Destructor was called" << std::endl;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getisSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

std::ostream& operator<<(std::ostream& o, const AForm& b){
    o << b.getName() << ", AForm gradeToSign " << b.getGradeToSign() << ", AForm gradeToExecute " << b.getGradeToExecute() << ", sign flag " << b.getisSigned() << ".";
    return o;
}

void AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

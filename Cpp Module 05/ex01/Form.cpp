#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	// std::cout << "Form Default constructor was called" << std::endl;
}

Form::Form(const Form &obj) : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
	// std::cout << "Form Copy constructor was called" << std::endl;
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	// std::cout << "Form Parameterized constructor was called" << std::endl;
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form& Form::operator=(const Form &obj)
{
	// std::cout << "Form Copy assignment was called" << std::endl;
	if (this != &obj)
		isSigned = obj.isSigned;
	return *this;
}

Form::~Form()
{
	// std::cout << "Form Destructor was called" << std::endl;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getisSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

std::ostream& operator<<(std::ostream& o, const Form& b){
    o << b.getName() << ", Form gradeToSign " << b.getGradeToSign() << ", Form gradeToExecute " << b.getGradeToExecute() << ", sign flag " << b.getisSigned() << ".";
    return o;
}

void Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

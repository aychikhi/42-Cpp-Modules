#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    // std::cout << "Bureaucrat Constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    // std::cout << "Bureaucrat Parameterized Constructor was called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
    // std::cout << "Bureaucrat Copy Constructor was called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    // std::cout << "Bureaucrat Copy assignment was called" << std::endl;
    if (this != &obj)
        this->grade = obj.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{   
    // std::cout << "Bureaucrat Destructor was called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}

void Bureaucrat::signForm(Form &obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << name << " signed " << obj.getName() << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << name << " couldn't sign " << obj.getName() << " because " << ex.what() << std::endl;
	}
}
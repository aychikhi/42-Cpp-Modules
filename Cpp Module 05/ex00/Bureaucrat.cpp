#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    // std::cout << "Constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    // std::cout << "Parameterized Constructor was called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
    // std::cout << "Copy Constructor was called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
    // std::cout << "Copy assignment was called" << std::endl;
    if (this != &obj)
        this->grade = obj.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{   
    // std::cout << "Destructor was called" << std::endl;
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

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
		void signForm(Form  &obj);
        class GradeTooHighException : public std::exception
        {
            public:
                    virtual const char* what() const throw()
                    {
                        return "Grade is too High";
                    }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                    virtual const char* what() const throw()
                    {
                        return "Grade is too Low";
                    }
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif
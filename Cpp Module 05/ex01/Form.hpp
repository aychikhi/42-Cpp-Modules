#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        Form();
        Form(const Form &obj);
        Form(std::string name, const int gradeToSign, const int gradeToExecute);
        Form &operator=(const Form &obj);
		~Form();
		std::string getName() const;
		bool getisSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &obj);
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

std::ostream& operator<<(std::ostream& o, const Form& b);

#endif
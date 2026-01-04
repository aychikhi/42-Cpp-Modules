#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const AForm &obj);
        AForm(std::string name, const int gradeToSign, const int gradeToExecute);
        AForm &operator=(const AForm &obj);
		virtual ~AForm();
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
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& o, const AForm& b);

#endif
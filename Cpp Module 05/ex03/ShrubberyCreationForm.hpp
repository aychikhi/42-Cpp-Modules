#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
		virtual ~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};

#endif
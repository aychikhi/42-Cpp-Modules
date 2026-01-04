#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm* rrf;

    std::cout << "--- Test 1: Subject Example (Robotomy Request) ---" << std::endl;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test 2: Shrubbery Creation ---" << std::endl;
    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf)
    {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    std::cout << "\n--- Test 3: Invalid Form Name ---" << std::endl;
    AForm* unknown;

    unknown = someRandomIntern.makeForm("coffee making", "Kitchen");
    if (!unknown)
    {
        std::cout << "Successfully handled invalid form request." << std::endl;
    }

    return 0;
}
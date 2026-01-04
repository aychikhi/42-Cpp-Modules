#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{

    std::srand(std::time(0));

    try {

        Bureaucrat boss("Boss", 1);        
        Bureaucrat intern("Intern", 150);  


        ShrubberyCreationForm shrub("home");       
        RobotomyRequestForm robot("Bender");      
        PresidentialPardonForm pardon("Criminal"); 

        std::cout << "--- Testing Shrubbery ---" << std::endl;
        boss.signForm(shrub);      
        boss.executeForm(shrub);  

        std::cout << "\n--- Testing Robotomy ---" << std::endl;
        boss.signForm(robot);     
        boss.executeForm(robot);  
        boss.executeForm(robot);   

        std::cout << "\n--- Testing Presidential Pardon ---" << std::endl;
        boss.signForm(pardon);     
        boss.executeForm(pardon); 

        std::cout << "\n--- Testing Failure (Intern trying to execute) ---" << std::endl;
        intern.executeForm(pardon); 

    } catch (std::exception &e) {
        std::cout << "Global Exception: " << e.what() << std::endl;
    }

    return 0;
}
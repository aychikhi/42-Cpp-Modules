#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // --- Test 1: Normal initialization and << operator ---
    std::cout << "--- Test 1: Form Basics ---" << std::endl;
    try 
    {
        Form f1("Standard Contract", 50, 25);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // --- Test 2: Invalid Form Grade (Too High) ---
    std::cout << "\n--- Test 2: Form Grade Too High (Constructor) ---" << std::endl;
    try 
    {
        Form f2("Illegal Form", 0, 50);
    }
    catch (std::exception &e) 
    {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    // --- Test 3: Successful Signing ---
    std::cout << "\n--- Test 3: Successful Sign ---" << std::endl;
    try 
    {
        Bureaucrat Mraytet("The Mraytet", 1);
        Form Mform("Nuclear Launch Codes", 1, 1);
        
        std::cout << Mform << std::endl;
        Mraytet.signForm(Mform);
        std::cout << Mform << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << "Unexpected Exception: " << e.what() << std::endl;
    }

    // --- Test 4: Failed Signing (Grade Too Low) ---
    std::cout << "\n--- Test 4: Failed Sign (Grade Too Low) ---" << std::endl;
    try 
    {
        Bureaucrat Mdahsess("The Mdahsess", 150);
        Form secret("Top Secret Document", 1, 1);
        
        std::cout << secret << std::endl;
        Mdahsess.signForm(secret);
        std::cout << secret << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << "Caught unexpected error in main: " << e.what() << std::endl;
    }

    return 0;
}
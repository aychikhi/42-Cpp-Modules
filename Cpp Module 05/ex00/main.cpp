#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}

int main()
{
    // --- Test 1: Normal initialization and << operator ---
    std::cout << "--- Test 1: Normal Bureaucrat ---" << std::endl;
    try 
    {
        Bureaucrat lmraytet("lmraytet", 2);
        std::cout << lmraytet << std::endl;
        
        lmraytet.incrementGrade();
        std::cout << "After promotion: " << lmraytet << std::endl;
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // --- Test 2: Grade too high in constructor ---
    std::cout << "\n--- Test 2: Grade Too High (Constructor) ---" << std::endl;
    try 
    {
        Bureaucrat lmhaytek("lmhaytek", 0);
    }
    catch (std::exception &e) 
    {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    // --- Test 3: Grade too low in constructor ---
    std::cout << "\n--- Test 3: Grade Too Low (Constructor) ---" << std::endl;
    try 
    {
        Bureaucrat lmdahech("lmdahech", 151);
    }
    catch (std::exception &e) 
    {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    // --- Test 4: Exception during increment ---
    std::cout << "\n--- Test 4: Exception during Increment ---" << std::endl;
    try 
    {
        Bureaucrat lmdahssess("lmdahssess", 1);
        std::cout << lmdahssess << std::endl;
        lmdahssess.incrementGrade();
    }
    catch (std::exception &e) 
    {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// tests with virtual
	Animal *an = new Dog();
    Animal *an2 = new Cat();

    std::cout << an->getType() << std::endl;
    an->makeSound();


    std::cout << an2->getType() << std::endl;
    an2->makeSound();

    delete an;
    delete an2;

	//tests without virtual
	// WrongAnimal *an = new WrongCat();

    // std::cout << an->getType() << std::endl;
    // an->makeSound();

    // delete an;
	return 0;
}
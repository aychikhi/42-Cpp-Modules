#include "./includes/Animal.hpp"
#include "./includes/Dog.hpp"
#include "./includes/Cat.hpp"
#include "./includes/Brain.hpp"

int main()
{

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    for(int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }
    
    for(int i = 0; i < 4; i++) {
        delete animals[i];
    }
    
	//testing deep copy
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1);  
    delete dog1;  
    dog2->makeSound();  
    delete dog2;
    
    return 0;
}
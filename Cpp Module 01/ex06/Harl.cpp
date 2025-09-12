#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl; 
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n"  << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	std::string cases[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (level != cases[i] && i < 4)
		i++;
	switch (i)
	{
		case 0: this->debug();
		case 1: this->info();
		case 2: this->warning();
		case 3: this->error();
			break;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; 
	}
}
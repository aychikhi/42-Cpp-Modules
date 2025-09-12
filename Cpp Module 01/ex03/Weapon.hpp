#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weopon
{
	private:
		std::string type;
	public:
		Weopon(std::string type);
		~Weopen(void);
		std::string& getType();
		void	setType(std::string newType);
};

#endif
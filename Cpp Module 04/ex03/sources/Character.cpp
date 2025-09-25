#include "../includes/Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
    Name = "default";
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
	Head = NULL;
}

Character::Character(const std::string &Name)
{
    std::cout << "Character parameterized constructor called" << std::endl;
    this->Name = Name;
    for (int i = 0; i < 4; i++)
        slots[i] = NULL;
	Head = NULL;
}

Character::Character(const Character &obj)
{
    std::cout << "Character copy constructor called" << std::endl;
	Head = NULL;
    Name = obj.Name;
    for (int i = 0; i < 4; i++)
    {
        if (obj.slots[i])
            slots[i] = obj.slots[i]->clone();
        else
            slots[i] = NULL;
    }
}

Character &Character::operator=(const Character &obj)
{
    std::cout << "Character copy assignment called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            delete slots[i];
            slots[i] = NULL;
        }
		delete_all();
        Head = NULL;
        Name = obj.Name;
        for (int i = 0; i < 4; i++)
        {
            if (obj.slots[i])
                slots[i] = obj.slots[i]->clone();
            else
                slots[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        delete slots[i];
        slots[i] = NULL;
    }
	delete_all();
}

std::string const &Character::getName() const
{
    return Name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!slots[i])
        {
            slots[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && slots[idx])
    {
		addback(slots[idx]);
        slots[idx] = NULL;
    }
	else 
		std::cout << "invalid index: " << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && slots[idx])
    {
        slots[idx]->use(target);
    }
	else
		std::cout << "Invalid inventory index or empty slot" << std::endl;
}

void Character::addback(AMateria *m)
{
	if (!m)
		return ;
	struct Node *newNode = new struct Node;
	newNode->m = m;
	newNode->next = NULL;
	if (!Head)
	{
		Head = newNode;
		return;
	}
	struct Node *tmp = Head; 
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newNode;
}

void Character::delete_all()
{
	struct Node *tmp = Head;
	while (Head)
	{
		tmp = Head;
		Head = Head->next;
		delete tmp->m;
		delete tmp;	
	}
	Head = NULL;
}
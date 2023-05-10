#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "[FT] " << name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src._name) {
	this->_hp = 100;
	this->_ep = 100;
	this->_atkDmg = 30;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << "[FT] " << this->_name << " destroyed." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_atkDmg = rhs._atkDmg;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, FragTrap const &i) {
	o << "FragTrap = " << i.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::attack(const std::string &target) {
	if (this->consumeEnergy(1) && this->getHp() > 0) {
		std::cout << "[FT] " << this->_name << " hits " << target
				  << " with a hammer, causing " << this->_atkDmg
				  << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "[FT] "
			  << "GIME FIVE, GUYS!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
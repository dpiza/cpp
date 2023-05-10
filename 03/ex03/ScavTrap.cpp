#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "[ST] " << name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src._name) {
	this->_hp = 100;
	this->_ep = 50;
	this->_atkDmg = 20;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << "[ST] " << this->_name << " destroyed." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_atkDmg = rhs._atkDmg;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &i) {
	o << "ScavTrap = " << i.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const std::string &target) {
	if (this->consumeEnergy(1) && this->getHp() > 0) {
		std::cout << "[ST] " << this->_name << " hits hard " << target
				  << "'s face, causing " << this->_atkDmg
				  << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << "[ST] " << this->getName() << " is in Gate keeper mode"
			  << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
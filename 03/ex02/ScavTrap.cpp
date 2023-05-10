#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "Wild ScavTrap named " << name << " appeared." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src)
	: ClapTrap(src._name, src._hp, src._ep, src._atkDmg) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() { std::cout << this->_name << " vanished." << std::endl; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atkDmg = rhs.getAtkDmg();
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
		std::cout << this->_name << " hits hard " << target
				  << "'s face, causing " << this->_atkDmg
				  << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << this->getName() << " is in Gate keeper mode" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
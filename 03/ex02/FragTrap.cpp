#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "Wild FragTrap named " << name << " appeared." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
	: ClapTrap(src._name, src._hp, src._ep, src._atkDmg) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {
	std::cout << this->_name << " went bye bye." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atkDmg = rhs.getAtkDmg();
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
		std::cout << this->_name << " hits " << target
				  << " with a hammer, causing " << this->_atkDmg
				  << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "GIME FIVE, GUYS!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"),
	  FragTrap(name + "_clap_name"), _name(name) {

	std::cout << "[DT] " << name << " created." << std::endl;

	FragTrap::_hp = 100;
	ScavTrap::_ep = 50;
	FragTrap::_atkDmg = 30;

	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_atkDmg = FragTrap::_atkDmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
	: ClapTrap(src._name + "_clap_name"), ScavTrap(src._name + "_clap_name"),
	  FragTrap(src._name + "_clap_name"), _name(src._name) {
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_atkDmg = src._atkDmg;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap() {
	std::cout << "[DT] " << this->_name << " destroyed." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_atkDmg = rhs._atkDmg;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, DiamondTrap const &i) {
	o << "DiamondTrap = " << i.getName();
	return o;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI(void) {
	std::cout << "[DT] "
			  << "Name is " << this->_name << " aka " << ClapTrap::getName()
			  << " by my kind." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
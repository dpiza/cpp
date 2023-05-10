#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hp(10), _ep(10), _atkDmg(0) {
	std::cout << "Wild ClapTrap named " << name << " appeared." << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int atkDmg)
	: _name(name), _hp(hp), _ep(ep), _atkDmg(atkDmg) {
	std::cout << "Wild ClapTrap named " << name << " appeared." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) { *this = src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	std::cout << this->_name << " was disassembled." << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	if (this != &rhs) {
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_ep = rhs.getEp();
		this->_atkDmg = rhs.getAtkDmg();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i) {
	o << "ClapTrap = " << i.getName();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::status(void) {
	std::cout << "[ClapTrap Name: " << this->getName();
	std::cout << " | HP: " << this->getHp();
	std::cout << " | EP: " << this->getEp();
	std::cout << " | ATK: " << this->getAtkDmg() << "]" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->consumeEnergy(1) && this->getHp() > 0) {
		std::cout << this->_name << " attacks " << target << " causing "
				  << this->_atkDmg << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->consumeEnergy(1) && this->getHp() > 0) {
		this->setHp(this->getHp() + amount);
		std::cout << this->_name << " was healed for " << amount << " hp."
				  << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHp() > 0) {
		this->setHp(this->getHp() - amount);
		std::cout << this->_name << " has been hit with " << amount
				  << " atk dmg!" << std::endl;
		if (this->getHp() <= 0) {
			std::cout << this->_name << " was destroyed!" << std::endl;
		}
	}
}

bool ClapTrap::consumeEnergy(int amount) {
	if (this->getEp() - amount > 0) {
		this->setEp(this->getEp() - amount);
		return (true);
	}
	return (false);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ClapTrap::getName(void) const { return this->_name; }

void ClapTrap::setName(int value) { this->_name = value; }

int ClapTrap::getAtkDmg(void) const { return this->_atkDmg; }

void ClapTrap::setAtkDmg(int value) { this->_atkDmg = value; }

int ClapTrap::getHp(void) const { return this->_hp; }

void ClapTrap::setHp(int value) { this->_hp = value; }

int ClapTrap::getEp(void) const { return this->_ep; }

void ClapTrap::setEp(int value) { this->_ep = value; }

/* ************************************************************************** */
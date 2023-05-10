#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {

  public:
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &src);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &rhs);

	void whoAmI(void);
	void attack(const std::string &);

  private:
	std::string _name;
};

std::ostream &operator<<(std::ostream &o, DiamondTrap const &i);

#endif /* ***************************************************** DIAMONDTRAP_H  \
		*/
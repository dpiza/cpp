#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {

  public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(ScavTrap const &src);
	~ScavTrap();

	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(const std::string &);
	void guardGate(void);

  private:
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &i);

#endif /* ******************************************************** SCAVTRAP_H  \
		*/
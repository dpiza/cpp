#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap {

  public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(ScavTrap const &);
	~ScavTrap();

	ScavTrap &operator=(ScavTrap const &);

	void attack(const std::string &);
	void guardGate(void);

  private:
};

std::ostream &operator<<(std::ostream &, ScavTrap const &);

#endif /* ******************************************************** SCAVTRAP_H  \
		*/
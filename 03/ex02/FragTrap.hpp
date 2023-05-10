#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {

  public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(FragTrap const &);
	~FragTrap();

	FragTrap &operator=(FragTrap const &);

	void attack(const std::string &);
	void highFivesGuys(void);

  private:
};

std::ostream &operator<<(std::ostream &, FragTrap const &);

#endif /* ******************************************************** FRAGTRAP_H  \
		*/
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

  public:
	ClapTrap(std::string);
	ClapTrap(std::string, int, int, int);
	ClapTrap(ClapTrap const &);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &);

	void status(void);
	void attack(const std::string &);
	void takeDamage(unsigned int);
	void beRepaired(unsigned int);
	bool consumeEnergy(int);

	std::string getName(void) const;
	void setName(int);
	int getAtkDmg(void) const;
	void setAtkDmg(int);
	int getHp(void) const;
	void setHp(int);
	int getEp(void) const;
	void setEp(int);

  protected:
	std::string _name;
	int _hp;
	int _ep;
	int _atkDmg;
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif /* ******************************************************** CLAPTRAP_H  \
		*/
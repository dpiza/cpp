#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

#define N_ZOMBIES 10

class Zombie {
  private:
	std::string _name;

  public:
	Zombie(void);
	~Zombie(void);

	void announce(void);
	void setName(std::string);
};

Zombie *zombieHorde(int, std::string);

#endif

#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "A new zombie emerges from the dead" << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << this->_name << " was shot dead. Like, real dead this time."
			  << std::endl;
	return;
}

void Zombie::announce(void) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) { this->_name = name; }

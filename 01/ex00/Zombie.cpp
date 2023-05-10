#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "A new zombie called " << this->_name
			  << " emerges from the dead" << std::endl;
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
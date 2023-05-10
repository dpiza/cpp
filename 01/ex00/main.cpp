#include "Zombie.hpp"

int main(void) {
	std::cout << "== ZombieFactory 2077 ==" << std::endl;

	std::cout << std::endl << "HEAP" << std::endl << std::endl;
	Zombie *heapZombie = newZombie("heapZombie");
	Zombie *heapZombieTwo = newZombie("heapZombie 2.0");
	Zombie *heapZombieReturns = newZombie("heapZombie Returns");

	heapZombie->announce();
	heapZombieTwo->announce();
	heapZombieReturns->announce();

	delete heapZombie;
	delete heapZombieTwo;
	delete heapZombieReturns;

	std::cout << std::endl << "STACK" << std::endl << std::endl;
	randomChump("stackZombie");
	randomChump("stackZombier");
	randomChump("stackZombiest");

	return (0);
}
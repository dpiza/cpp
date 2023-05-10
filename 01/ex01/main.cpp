#include "Zombie.hpp"
#include <sstream>

int main(void) {
	Zombie *horde = zombieHorde(N_ZOMBIES, "Gary");

	for (int i = 0; i < N_ZOMBIES; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt("Coal");

	std::cout << std::endl;

	dt.whoAmI();
	std::cout << std::endl;
	dt.attack("Pebble");
	std::cout << std::endl;
	dt.highFivesGuys();
	std::cout << std::endl;
	dt.guardGate();
	std::cout << std::endl;
}
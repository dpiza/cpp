#include "ClapTrap.hpp"

int main() {
	{
		ClapTrap cp("Pikachu");
		cp.attack("Squirtle");
		cp.takeDamage(9);
		cp.beRepaired(5);
		cp.attack("Squirtle");
		cp.takeDamage(9);
		cp.beRepaired(1);
	}
	std::cout << std::endl;
	{
		ClapTrap cp("Pikachu");
		cp.attack("Geodude");
		cp.takeDamage(0);
		cp.beRepaired(5);
		cp.attack("Geodude");
		cp.takeDamage(0);
		cp.beRepaired(5);
		cp.attack("Geodude");
		cp.takeDamage(0);
		cp.beRepaired(5);
		cp.attack("Geodude");
		cp.takeDamage(0);
		cp.beRepaired(5);
		cp.attack("Geodude");
		cp.takeDamage(0);
		cp.beRepaired(5);
	}
	std::cout << std::endl;
	{
		ClapTrap cp("Pikachu");
		cp.attack("Charmander");
		cp.takeDamage(5);
		cp.beRepaired(5);
		cp.attack("Charmander");
		cp.takeDamage(5);
		cp.beRepaired(5);
		cp.attack("Charmander");
		cp.takeDamage(5);
		cp.beRepaired(5);
	}
}
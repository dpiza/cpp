#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap ct("Twin Cities");
	ScavTrap st("Noisy Boy");
	FragTrap ft("Midas");

	ct.status();
	st.status();
	ft.status();

	st.attack("Twin Cities");
	ct.takeDamage(20);
	st.guardGate();

	ft.highFivesGuys();
}
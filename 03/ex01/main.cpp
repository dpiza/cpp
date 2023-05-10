#include "ScavTrap.hpp"

int main() {
	ScavTrap st("Noisy Boy");
	ClapTrap ct("Twin Cities");
	ct.status();
	st.status();

	st.attack("Twin Cities");
	st.guardGate();
	st.takeDamage(200);
}
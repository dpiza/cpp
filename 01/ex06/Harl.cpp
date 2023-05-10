#include "Harl.hpp"

Harl::Harl(void) { return; }

Harl::~Harl(void) { return; }

void Harl::complain(std::string level) {
	funcPtr ptr = _getMember(level);

	(this->*ptr)();
}

void Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl
			  << "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special ketchup burger. I "
				 "really do!"
			  << std::endl
			  << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You "
				 "didn’t put enough bacon in my burger! If you did, I "
				 "wouldn’t be asking for more!"
			  << std::endl
			  << std::endl;
}

void Harl::warning(void) {
	std::cout
		<< "[WARNING]" << std::endl
		<< "I think I deserve to have some extra bacon for free. "
		   "I’ve been "
		   "coming for years whereas you started working here since last month."
		<< std::endl
		<< std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl
			  << std::endl;
}

void Harl::misc(void) {
	std::cout << "[ Probably complaining about insignificant problems ]"
			  << std::endl
			  << std::endl;
}

funcPtr Harl::_getMember(std::string level) {
	funcPtr ptr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error,
					 &Harl::misc};
	std::string list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index;

	for (index = 0; index < 4; index++) {
		if (level.compare(list[index]) == 0)
			break;
	}

	return ptr[index];
}

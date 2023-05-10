#include "Harl.hpp"

void validateInput(int c) {
	if (c != 2) {
		std::cout << "Invalid arguments" << std::endl;
		exit(1);
	}
}

int getLogLevel(char *arr) {
	std::string list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level;

	for (level = 0; level < 4; level++) {
		if (std::string(arr).compare(list[level]) == 0)
			break;
	}

	return level;
}

void runDebug(Harl &harl) {
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
}

void runInfo(Harl &harl) {
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
}

void runWarning(Harl &harl) {
	harl.complain("WARNING");
	harl.complain("ERROR");
}

void runError(Harl &harl) { harl.complain("ERROR"); }

void runMisc(Harl &harl) { harl.complain(""); }

int main(int c, char **v) {
	validateInput(c);
	int level = getLogLevel(v[1]);
	Harl harl;

	switch (level) {
	case 0:
		runDebug(harl);
		break;
	case 1:
		runInfo(harl);
		break;
	case 2:
		runWarning(harl);
		break;
	case 3:
		runError(harl);
		break;
	default:
		runMisc(harl);
		break;
	}
	exit(0);
}
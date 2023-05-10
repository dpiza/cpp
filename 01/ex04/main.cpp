#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

void validateInput(int c) {
	if (c != 4) {
		std::cout << "Invalid arguments" << std::endl;
		exit(1);
	}
}

void openInputFile(char *arr, std::ifstream &inputFile) {
	inputFile.open(arr);
	if (!inputFile.is_open()) {
		std::cout << "invalid filename" << std::endl;
		exit(1);
	}
}

void openOutputFile(char *arr, std::ofstream &outputFile) {
	std::string outputFileName(arr);
	outputFileName.append(".replace");
	outputFile.open(outputFileName.c_str(), std::ios::out | std::ios::trunc);
}

void replaceString(std::string &line, char *pullArr, char *pushArr) {
	std::string pull(pullArr);
	std::string push(pushArr);
	size_t pos = 0;

	while (pos != std::string::npos) {
		pos = line.find(pull, pos);
		if (pos != std::string::npos) {
			line.erase(pos, pull.size());
			line.insert(pos, push);
			pos += push.size();
		}
	}
}

int main(int c, char **v) {
	validateInput(c);

	std::ifstream inputFile;
	std::ofstream outputFile;

	openInputFile(v[1], inputFile);
	openOutputFile(v[1], outputFile);

	std::string line;

	while (std::getline(inputFile, line)) {
		replaceString(line, v[2], v[3]);
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
	return (0);
}
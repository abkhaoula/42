#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) {
	if (argc != 4)
	{
		std::cout << "Expected 3 arguments (fileName S1 S2). Received " <<  (argc - 1) << " arguments!" << std::endl;
		return (0);
	}

	std::ifstream file(argv[1]);
	if (!file) {
		std::cout << "Couldn't open " << argv[1] << std::endl;
		return (0);
	}

	std::ofstream file_replace((std::string(argv[1]) + ".replace").data());
	if (!file_replace) {
		std::cout << "Couldn't open " << std::string(argv[1]) + ".replace" << std::endl;
		return (0);
	}

	std::string line;

	while (std::getline(file, line)) {
    	size_t pos = 0;
		while ((pos = line.find(argv[2], pos)) != std::string::npos) {
			line.replace(pos, std::strlen(argv[2]), argv[3]);
			pos += std::strlen(argv[3]);
    	}
		file_replace << line << std::endl;
	}

	return (0);
}


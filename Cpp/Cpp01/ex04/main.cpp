/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:23:59 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:24:00 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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
	std::string rline;

	line = "";
	while (std::getline(file, rline)) {
		line = line + rline;
		line = line + "\n";
	}
	line.erase(line.length() - 1, 1);

	//std::cout << "line comming :"<< std::endl << std::endl;
	//std::cout << line << std::endl << "--------------------------" << std::endl;
	//return 0;


    size_t pos = 0;
    while ((pos = line.find(argv[2], pos)) != std::string::npos) {
    	line.insert(pos, argv[3]);
      	line.erase(pos + strlen(argv[3]), strlen(argv[2]));
      	pos += strlen(argv[3]);
	}

    file_replace << line;





	//while (std::getline(file, line)) {
	//	file_replace << '\n';
    //	size_t pos = 0;
    //	while ((pos = line.find(argv[2], pos)) != std::string::npos) {
    //  		line.insert(pos, argv[3]);
    //  		line.erase(pos + strlen(argv[3]), strlen(argv[2]));
    //  		pos += strlen(argv[3]);
	//	}

    //	file_replace << line;
	//}

	return (0);
}


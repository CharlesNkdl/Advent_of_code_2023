#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "Clues.class.hpp"

int main(void)
{
	Clues clues;
	std::string buffer;

	std::ifstream file("input.txt");
	if (file.is_open())
	{
		while (getline(file, buffer))
		{
			clues.setClues(buffer);
		}
		file.close();
		std::cout << clues.getTotal() << std::endl;
	}
	else
		std::cout << "Erreur ouverture" << std::endl;

	return (0);
}

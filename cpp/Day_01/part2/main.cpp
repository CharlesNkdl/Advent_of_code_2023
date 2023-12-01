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
			clues.transformClues();
			clues.addTotal();

		}
		file.close();
		std::cout << clues.getTotal() << std::endl;
	}
	else
		std::cout << "Erreur ouverture" << std::endl;

	/*buffer = "two1nine";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;
	buffer = "eightwothree";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;
	buffer = "abcone2threexyz";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;
	buffer = "xtwone3four";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;
	buffer = "4nineeightseven2";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;
	buffer = "zoneight234";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;
	buffer = "7pqrstsixteen";
	clues.setClues(buffer);
	clues.transformClues();
	clues.addTotal();
	std::cout << clues.getClues() << std::endl;
	std::cout << clues.getTotal() << std::endl;*/


	return (0);
}

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "Bag.class.hpp"

int main(void)
{
	Bag bag;
	std::string buffer;
	int gameNbr;

	gameNbr = 1;
	bag.setCubes(12, 13, 14);
	std::ifstream file("input.txt");
	if (file.is_open())
	{
		while (getline(file, buffer))
		{
			bag.setInput(buffer, gameNbr);
			bag.setCubes(0,0,0);
			bag.results();
			bag.resultspergame();
			gameNbr++;
		}
		file.close();
		std::cout << bag.getTotal() << std::endl;
	}
	else
		std::cout << "Erreur ouverture" << std::endl;

	/*buffer = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
	bag.setInput(buffer, gameNbr);
	bag.results();
	bag.resultspergame();
	std::cout << bag.getTotal() << std::endl;*/



	return (0);
}

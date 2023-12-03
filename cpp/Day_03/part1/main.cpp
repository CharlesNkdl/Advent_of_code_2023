#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "Mappeur.class.hpp"

int main(void)
{
	Mappeur mappeur;
	std::string buffer;
	int line;

	line = 0;
	std::ifstream file("input.txt");
	if (file.is_open())
	{
		while (getline(file, buffer))
		{
			mappeur.setInput(buffer,line);
			line++;
		}
		file.close();
		mappeur.results();
		std::cout << mappeur.getTotal() << std::endl;
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

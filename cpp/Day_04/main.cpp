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
			clues.getNumbers();
			clues.addTotal();
		}
		file.close();
		std::cout << clues.countScratch() << std::endl;
	}
	else
		std::cout << "Erreur ouverture" << std::endl;

	/*clues.setClues("Card   1: 42 68 56  3 28 97  1 78 55 48 | 78 54  3 38 94 73 72 57 51 31 86 43  7 81  4 27 26 58 75 69 74 55  5 28 40");
	clues.getNumbers();
	clues.addTotal();
	std::cout << clues.getTotal() << std::endl;

	clues.setClues("Card 196: 14 50 34 21 81 27  9 57 58 72 | 34 33 86 85 19 62 60 25 64 92 31 53 18 35 20 82 91 95 71 36 78 77 87 89 22");
	clues.getNumbers();
	clues.addTotal();
	std::cout << clues.getTotal() << std::endl;

	clues.setClues("Card 140: 87 51 66 93 54 74 27 88 26 81 | 59 61 60 38  1 52 44 76 68 85  9 64 69 43 65  6 48 41  5 79  4 95 25 98 81");
	clues.getNumbers();
	clues.addTotal();
	std::cout << clues.getTotal() << std::endl;*/

	return (0);
}

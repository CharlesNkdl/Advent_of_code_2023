#ifndef CLUES_HPP
#define CLUES_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

class Clues
{
	private :
		int total;
		std::string clues;
		int numbers[12];
		int goodnumbers;
		int cards;
		int goodnumberspercard[204];

	public :
		Clues();
		void setClues(std::string);
		char getLast();
		void getNumbers();
		void addTotal();
		int countScratch();
		int getTotal();
};


#endif

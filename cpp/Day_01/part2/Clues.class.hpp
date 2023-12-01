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

	public :
		Clues() : total(0) {};
		void setClues(std::string);
		void transformClues();
		char getLast();
		char getFirst();
		void addTotal();
		int getTotal();
		std::string getClues();
};


#endif
